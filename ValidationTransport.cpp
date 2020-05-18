#include "ValidationTransport.h"

ValidationTransport::ValidationTransport()
{
	errors = 0;
}

ValidationTransport::~ValidationTransport()
{
}

int ValidationTransport::validate(Transport* transport)
{
	errors = 0;
	if (transport->getModel() < 0)
	{
		errors++;
		message += " The model doesn't have to negative! ";
	}
	if (transport->getProducator() == "")
	{
		errors++;
		message += " The arrival location doesn't have to be empty! ";
	}
	if (transport->getNumar_vagoane() <= 0)
	{
		errors++;
		message += " The depparture location doesn't have to be empty! ";
	}
	if (transport->getGarnituri_disponibile() <= 0)
	{
		errors++;
		message += " The total number of seats must be positive! ";
	}
	if (transport->getGarnituri_rezervate() <= 0)
	{
		errors++;
		message += " The number of reserved seats must be positive! ";
	}
	return errors;
}

string ValidationTransport::toString()
{
	return message;
}