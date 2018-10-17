#include "..\rt.h"
#include <iostream>
#include <stdio.h>


// put your semaphores here as global variables accessible by all threads
CSemaphore *EntryGate;
CSemaphore *ExitGate;
CSemaphore *Full;
CSemaphore *Empty;


class Passenger : public ActiveClass {
	int id;
public:
	// constructor if needed
	Passenger( int _id ) { 
		id = _id;
	}

private:
	int main(void)
	{
		// traffic logic
		EntryGate->Wait();
		Full->Signal();

		// rider is onboard
		printf("Rider %d is onboard. \n", id);
		SLEEP(15000);

		ExitGate->Wait();
		Empty->Signal();
		
		printf("Rider %d is getting off the car. \n", id);
		return 0;
	}
};

class RollerCoaster : public ActiveClass {

	int total_seat_number = 0;

public: 	

	// constructor if needed
	RollerCoaster( int number ) {
		total_seat_number = number;
	} 			

private:
	int main(void)
	{
		while (1) {

			for (int current = 0; current < total_seat_number; current++) {
				EntryGate->Signal();
			}

			for (int current = 0; current < total_seat_number; current++) {
				Full->Wait();
			}

			SLEEP(1000);
			// Roller Coaster goes ride from here
			printf("The roller coaster goes ride now \n");

			for (int current = 0; current < total_seat_number; current++) {
				ExitGate->Signal();
			}

			for (int current = 0; current < total_seat_number; current++) {
				Empty->Wait();
			}

			SLEEP(300);

			printf("The roller is empty, ready for loading .... \n\n\n");
		}
		return 0;
	}
};

int main()
{	
	EntryGate = new CSemaphore("EntryGate", 0, 30);
	ExitGate = new CSemaphore("ExitGate", 0, 30);
	Full = new CSemaphore("Full", 0, 30);
	Empty = new CSemaphore("Empty", 0, 30);


	RollerCoaster RollerCoaster1(30);		// create the single rollercoaster
	RollerCoaster1.Resume();			// let it run

	SLEEP(1000);			// wait for it initialise itself

	printf("Welcome to the Roller Coaster Game \n");

	Passenger	*thePassengers[100];		// create 100 passenger pointers

the_line_up:
	for (int i = 0; i < 100; i++) {
		thePassengers[i] = new Passenger(i);	// create 100 passengers
		SLEEP(300);
		thePassengers[i]->Resume();		// let them run
	}
	goto the_line_up;
	 	// wait for rollercoater thread to terminate, even though it doesn't to prevent the parent thread 	// (i.e. this one from terminating and halting the program).
	
	RollerCoaster1.WaitForThread();
	return 0;
}
