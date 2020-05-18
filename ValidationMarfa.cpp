#include "ValidationMarfar.h"

ValidationMarfar::ValidationMarfar() : ValidationTransport()
{
}

ValidationMarfar::~ValidationMarfar()
{
}

int ValidationMarfar::validate(Transport* transport)
{
	Marfar* marfar = (Marfar*)transport;
	ValidationTransport::validate(marfar);
	if (marfar->getMarfa() == "" )
	{
		ValidationTransport::errors++;
		ValidationTransport::message += " The marfa must be txt value! ";
	}
	return errors;
}