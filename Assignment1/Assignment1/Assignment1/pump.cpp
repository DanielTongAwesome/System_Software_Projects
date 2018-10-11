#include "pump.h"

PumpClass::PumpClass(int input_pump_number)
{
	pump_number = input_pump_number;
	printf("Pump %d has been created \n", pump_number);
}

void PumpClass::Serving(int input_pump_speed)
{
	pump_status = 1;
	pump_speed = input_pump_speed;
}

void PumpClass::Stop_Serving()
{
	pump_status = 0;
	pump_speed = 0;
}

PumpClass::~PumpClass()
{
}
