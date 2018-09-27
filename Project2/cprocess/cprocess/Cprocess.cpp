

#include <process.h>	// for spawnl and createthread
#include <windows.h>	// for perror and sleep
#include <stdio.h>		// for printf
#include <limits.h>		// for UINT_MAX
#include <conio.h>		// for _kbhit(), getch() and getche()
#include <iostream>
#include <string>

using namespace std;

#define PerThreadStorage  __declspec(thread)
#define _CRT_SECURE_NO_WARNINGS	


#define SUSPENDED			101000		// for threads
#define ACTIVE				101001		// for thread
#define OWN_WINDOW			101002		// for FORK_PROCESS
#define PARENT_WINDOW		101003		// ditto
#define MAXMESSAGEVALUE		32000		// maximum value of a user generated message

#define MANUAL				101004		// for events
#define AUTORESET			101005		// for events

#define SINGLE_RELEASE		101100		// for events
#define MULTIPLE_RELEASE	101101		// for events

#define SIGNALLED			101006		// for events
#define NOTSIGNALLED		101007		// for events

#define OWNED				101008		// for mutex's
#define NOTOWNED			101009		// for mutex's

#define ECHO_ON()		/* no definition for OS9 compatibility */
#define ECHO_OFF()		/* no definition for OS9 compatibility */


string path_list_child3 = "C:\\Users\\13358\\Dropbox\\CPEN333Windows\\Project2\\Project2--PartA\\Debug\\PartAChild3.exe";

void PERR(bool bSuccess, string ErrorMessageString);
HANDLE	GET_STDOUT();				// ditto output device
void	MOVE_CURSOR(int x, int y);	// move console cursor to x,y coord
void	CURSOR_ON();				// turn flashing cursor on (the default)
void	CURSOR_OFF();				// turn flashing cursor off
void	REVERSE_ON();				// turn on inverse video
void	REVERSE_OFF();				// turn off inverse video


int main() {

	PROCESS_INFORMATION pInfo;
	const string ProcessName;		// name of process

	const string &Name = path_list_child3; 		// path/name of executable program (.exe)
	int Priority = NORMAL_PRIORITY_CLASS;			// Priority of the process
	BOOL bUseNewWindow = OWN_WINDOW;		// use OWN_WINDOW to make new process run in its own window
							// use PARENT_WINDOW to make it share its parent window
	BOOL bCreateSuspended = ACTIVE;	// use SUSPENDED to make new child process's main thread suspended when process is created
								// use ACTIVE to make new child processes main thread active when process iscreated

	const string &ChildProcessArgString = "";




	PERR(((Priority == HIGH_PRIORITY_CLASS) ||
		(Priority == IDLE_PRIORITY_CLASS) ||
		(Priority == NORMAL_PRIORITY_CLASS) ||
		(Priority == REALTIME_PRIORITY_CLASS)),
		string("Illegal 2nd Argument (Process Priority) for Process: ") + Name);


	PERR((bUseNewWindow == OWN_WINDOW || bUseNewWindow == PARENT_WINDOW),
		string("Use OWN_WINDOW or PARENT_WINDOW as 3rd argument for Process: ") + Name);
	PERR((bCreateSuspended == SUSPENDED || bCreateSuspended == ACTIVE),
		string("Use SUSPENDED or ACTIVE as 4th Argument for Process: ") + Name);


	STARTUPINFO	StartupInfo = {
		sizeof(STARTUPINFO) ,
		NULL ,			// reserved
		NULL ,			// ignored in console applications
		(char *)(Name.c_str()) ,	// displayed in title bar for console applications
		0,0,			// dwx, dwy, offset of top left of new window relative to top left of screen in pixel
						// flags below must specify STARTF_USEPOSITION. Ignored for console apps'
		0,0,			// dwxsize, dwysize: Width and height of the window if new window specified
						// must use flags STARTF_USESIZE. Ignored for console apps'
		0,0,			// size of console in characters, only if STARTF_USECOUNTCHARS flag specified, 
						// Ignored for console apps
		0,				// Colour control, for background and text. Ignored for console apps
		0,				// Flags. Ignored for console applications
		0,				// ignored unless showwindow flag set
		0 ,
		NULL,
		0,0,0			// stdin, stdout and stderr handles (inherited from parent)
	};

	UINT flags = Priority; // Priority,

	if (bUseNewWindow == OWN_WINDOW)		// if caller has specified that child should have its won window
		flags |= CREATE_NEW_CONSOLE;

	if (bCreateSuspended == SUSPENDED)	// if caller has specified that child process should be immediately suspended
		flags |= CREATE_SUSPENDED;

	BOOL Success = CreateProcess(NULL,	// application name
		(char *)(Name.c_str()),			// Command line to the process if you want to pass one to main() in the process
		NULL,			// process attributes
		NULL,			// thread attributes
		TRUE,			// inherits handles of parent
		flags,			// Priority and Window control flags,
		NULL,			// use environent of parent
		NULL,			// use same drive and directory as parent
		&StartupInfo,	// controls appearance of process (see above)
		&pInfo			// Stored process handle and ID into this object
	);
	PERR(Success == TRUE, string("CProcess Call Unable to Create New Process: ") + Name);	// check for error and print message if appropriate
}





void PERR(bool bSuccess, string ErrorMessageString)
{
	UINT LastError = GetLastError();

	if (!(bSuccess)) {
		char buff[512];
		Beep(500, 100);
		MOVE_CURSOR(0, 0);
		REVERSE_ON();
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, LastError,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), buff, 1024, NULL);
		printf(" Error %d in Process %s: line %d:\n", LastError, __FILE__, __LINE__);
		printf(" Translation: %s Error: %s", buff, ErrorMessageString.c_str());
		REVERSE_OFF();
		printf("\n\nPress Return to Continue...");
		_getch();
	}
}


//	moves the cursor to the x,y coord on the screen. [0,0] is top left
//	all calls to printf cause output to occur at the current cursor position
//	obviously, the cursor moves with text output operations

void MOVE_CURSOR(int x, int y)
{
	COORD	c = { (short)x, (short)y };
	SetConsoleCursorPosition(GET_STDOUT(), c);
}


//
//	These two functions turns on/off reverse video, so that text comes black on white background
//	For more details set the SetConsoleTextAttribute() function in on-line
//	help
//

void REVERSE_ON()
{
	SetConsoleTextAttribute(GET_STDOUT(),
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
}

void REVERSE_OFF()
{
	SetConsoleTextAttribute(GET_STDOUT(),
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}


HANDLE	GET_STDOUT()
{
	return GetStdHandle(STD_OUTPUT_HANDLE);
}



//
//	These two function turns off/on the cursor so that it is not visible
//	but it still operates and output text still occurs at the current curso
//	position
//

void CURSOR_OFF()
{
	CONSOLE_CURSOR_INFO	cci = { 1, FALSE };
	SetConsoleCursorInfo(GET_STDOUT(), &cci);
}

void CURSOR_ON()
{
	CONSOLE_CURSOR_INFO	cci = { 1, TRUE };
	SetConsoleCursorInfo(GET_STDOUT(), &cci);
}
