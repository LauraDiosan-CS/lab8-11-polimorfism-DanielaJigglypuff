#include "Exceptions.h"

Exceptions::Exceptions(string message) : message(message)
{
}

string Exceptions::getMessage()
{
	return message;
}