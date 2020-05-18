#include "ValidationCalatori.h"
#include <iostream>

ValidationCalatori::ValidationCalatori() : ValidationTransport()
{
}

ValidationCalatori::~ValidationCalatori()
{
}

int ValidationCalatori::validate(Transport* transport)
{
	cout << "woho discofrog  ";
	Calatori* calatori = (Calatori*)transport;
	ValidationTransport::validate(calatori);
	if (calatori->getLocuri() <= 0)
	{
		ValidationTransport::errors++;
		ValidationTransport::message += " The number of locuri must be positive! ";
	}
	return errors;
}