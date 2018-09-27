// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <iostream>
#include "CBulb.h"
#include "CSwitch.h"
#include "CLamp3Bulb.h"
#include "CPullLamp.h"
#include "list.h"
using namespace std;

int main(){
	//std::cout << "Hello World!\n";
	
	
	printf("#######  test of exercise 1 ####### \n\n");
	CBulb light1;
	CBulb light2(200);

	light1.print();
	//light1.set_state(1);
	light1.ON();
	light1.print();
	light1.OFF();

	light2.ON();
	light2.setwatts(2000);
	printf("\n\nThe real time power of the light is %d. \n", light2.getpower());

	printf("\n\n#######  test of exercise 2 #######  \n\n");

	CSwitch switch1;

	switch1.print();
	switch1.turnon();
	switch1.turnoff();

	
	printf("\n\n#######  test of exercise 3 #######  \n\n");

	
	CLamp3Bulb newLamp(20,30,40);
	newLamp.LampOn();
	newLamp.print();
	newLamp.LampOff();
	newLamp.print();
	newLamp.LampOn();
	printf("The current state of switch is %d. \n The current power is : %d. \n", newLamp.getState(), newLamp.getPower());

	
	printf("\n\n#######  test of exercise 4 #######  \n\n");
	
	CLamp3Bulb L1(100, 100, 100);
	L1.LampOn();
	L1.print();
	CBulb *b1 = new CBulb(60);
	
	b1 = L1.exchange(b1, 0);
	L1.print();
	delete b1;
	
	printf("\n\n#######  test of exercise 5 #######  \n\n");

	CLamp3Bulb L2(L1);
	
	L2.print();

	L1.LampOff();


	L2.print();

	printf("\n\n#######  test of exercise 6 #######  \n\n");
	
	CPullLamp Ltest(100, 100, 100);	// create a Pull Lamp with 3 x 100 watt bulbs

	Ltest.toggle();
	printf("Power of Lamp = %d\n", Ltest.getPower());	// print power

	CBulb *bulb1 = new CBulb(50);	// create new 50 watt bulb
	bulb1 = Ltest.exchange(bulb1, 0);	// swap bulb 0 for 50 watt bulb

	printf("Power of Lamp = %d\n", Ltest.getPower());	// print power
	Ltest.toggle();

	printf("Power of Lamp = %d\n", Ltest.getPower());	// print power

	delete bulb1;

	
	CPullLamp 	L6(100, 100, 100);	// create a Pull Lamp with 3 x 100 watt bulbs

	L6.toggle();
	printf("Power of Lamp = %d\n", L6.getPower());	// print power

	L6.toggle();
	printf("Power of Lamp = %d\n", L6.getPower());	// print power

	printf("\n\n#######  test of Part B exercise 2 #######  \n\n");
	List<int> test_list;
	// create a linked list from 1 to 5
	test_list.Insert(1);
	test_list.Insert(2);
	test_list.Insert(3);
	test_list.Insert(4);
	test_list.Insert(5);
	test_list.Delete();
	test_list.PrintList();
	printf("The 1st element is %d. \n", test_list.Get(1));
	printf("The 4nd element is %d. \n", test_list.Get(4));

	
	List<char> test_list_2;
	// create a linked list from 1 to 5
	test_list_2.Insert('a');
	test_list_2.Insert('b');
	test_list_2.Insert('c');
	test_list_2.Insert('d');
	test_list_2.Insert('e');
	test_list_2.Delete();
	test_list_2.PrintList();
	cout << "The 3rd element is " << test_list_2.Get(3) << "." << endl;



	printf("\n\n#######  test of Part B exercise 2 #######  \n\n");
	CBulb test_b1(10);
	List<CBulb*> test_list_3;
	test_list_3.Insert(&test_b1);
	//test_list_3.Delete();

	int   i = 5;
	CBulb test_b2(100);
	CSwitch test_s1();

	test_list_3.Insert(&test_b2);		// Error cannot add an int to a list that only accepts CBulb pointers
	test_list_3.PrintList();
	test_list_3.Delete();
	test_list_3.PrintList();
	// Error cannot add a switch pointer to this list 




	system("PAUSE");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
