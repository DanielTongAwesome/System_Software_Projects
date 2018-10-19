#include "Customer.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <ctime>
#include "..\rt.h"


// constructor of Customer to initialize name, consumption, credit_card, grade_of_gas
Customer::Customer(int _id)
{
	// customer id
	id = _id;
	
	// amount of consumption
	// no more than 70 liters
	srand(time(NULL));
	amount_oil = rand() % 71;

	//creadit card
	srand(time(NULL));
	int number1 = rand() % 9000 + 1000;
	int number2 = rand() % 9000 + 1000;
	int number3 = rand() % 9000 + 1000;
	int number4 = rand() % 9000 + 1000;
	credit_card = std::to_string(number1) + " " + std::to_string(number2) + " " + std::to_string(number3) + " " + std::to_string(number4);

	//grade_of_gas
	srand(time(NULL));
	int grade = rand() % 4;
	if (grade == 0) {
		grade = 87;
	}
	else if (grade == 1) {
		grade = 89;
	}
	else if (grade == 2) {
		grade = 91;
	}
	else if (grade == 3) {
		grade = 93;
	}

	// name
	name = "test_name" + std::to_string(id);
}

// customer destructor
Customer::~Customer()
{
}
