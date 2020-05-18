#include "Tests.h"
#include <cassert>
#include "Delete1.h"
#include "Delete2.h"

Tests::Tests()
{
}

Tests::~Tests()
{
}

void Tests::tests()
{
	/*
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	repositoryFileTransport->loadFromFile();
	Transport* c1 = new Marfar("156", "Cluj - Napoca", "Dubai", "14.06.2020", 100, 80, 0);
	Transport* c2 = new Calatori("873", "Constanta", "Brasov", "15.07.2020", 40, 20, 1);
	Transport* c3 = new Calatori("118", "Bucuresti", "Vienna", "11.06.2020", 80, 50, 3);
	service->addTransport(c1);
	service->addTransport(c2);
	service->addTransport(c3);
	try
	{
		service->remove("873", "Brasov");
		assert(service->getSizeTransport() == 2);
		assert(service->getTransport(0));
		assert(service->getTransport(1));
	}
	catch(Delete1& exc)
	{
		cout << "Exception: " << exc.getMessage();
		assert (false);
	}
	catch (Delete2 & exc)
	{
		cout << "Exception: " << exc.getMessage();
		assert(false);
	}


	
	try
	{
		service->remove("156", "Paris");
		assert(false);
	}
	catch (Delete1 & exc)
	{
		cout << "DeleteException1 thrown";
		assert(service->getSizeTransport() == 2);
		assert(service->getTransport(0) == c1);
		assert(service->getTransport(1) == c3);
	}
	catch (Delete2 & exc)
	{
		assert(false);
	}
		
	
	try
	{
		//Delete Trip with model “667”and Destination City “Fagaras”
		assert false;
	}
	catch
	{
		//DeleteException1
		assert false;
		//DeleteException2
		//Print “DeleteException2 thrown”
		assert(service->getSizeTransport() == 2);
		assert(service->getTransport(0) == c1);
		assert(service->getTransport(1) == c3);
	}

	try
	{
		//Delete Trip with model “156”and Destination City “Paris”
		assert false;
	}
	catch
	{
		//DeleteException2
		//Print “DeleteException2 thrown”
		//DeleteException1
		assert false;
	}
	try
	{
		//Delete Trip with model “667”and Destination City “Fagaras”
		assert false;
	}
	catch
	{
		//DeleteException2
		//Print “DeleteException2 thrown”
		//DeleteException1
		assert false;
	} */
}

void Tests::runTests()
{
	this->tests();
}