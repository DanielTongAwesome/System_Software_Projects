#include	<stdio.h>
#include	"../rt.h"			// change the pathlist to rt.h to suit location on your disk

int	main()
{
	printf("Child4 Process Creating the Pipeline.....\n");
	CPipe	MyPipe("Pipe4");							// Create a pipe with the name "Pipe2"

	printf("Parent Process Creating Child Process to Read from Pipeline.....\n");

	for (int x = 4000; x < 14050; x++) {
		printf("Child4 Writing %d to pipeline\n", x);
		MyPipe.Write(&x, sizeof(x));
		Sleep(1000);
	}

	return 0;
}
