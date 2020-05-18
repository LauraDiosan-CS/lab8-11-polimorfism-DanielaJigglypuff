#include "Service.h"
#include "Exceptions.h"
#include "ValidationException.h"
#include "ValidationMarfar.h"
#include "ValidationCalatori.h"
#include <string>

Service::Service(ValidationTransport* validation)
{
	this->validation = validation;
}

Service::Service(RepositoryFileTransport* repositoryFileTransport, RepositoryFileUser repositoryFileUser)
{
	this->repositoryFileTransport = repositoryFileTransport;
	this->repositoryFileUser = repositoryFileUser;
}

Service::~Service()
{
}

void Service::setRepository(RepositoryFileTransport* repositoryFileTransport, RepositoryFileUser repositoryFileUser)
{
	this->repositoryFileTransport = repositoryFileTransport;
	this->repositoryFileUser = repositoryFileUser;
}

void Service::addTransport(Transport* transport)
{
	try
	{
		repositoryFileTransport->addItem(transport);
	}
	catch (ValidationException& exception)
	{
		throw Exceptions(" Add error! " + exception.what());
	}
}

void Service::updateTransport(Transport* oldTransport, Transport* newTransport)
{
	try
	{
		repositoryFileTransport->updateItem(oldTransport, newTransport);
	}
	catch (ValidationException& exception)
	{
		throw Exceptions(" Add error! " + exception.what());
	}
}

void Service::deleteTransport(Transport* transport)
{

	if (repositoryFileTransport->findItem(transport) != -1)
	{
		repositoryFileTransport->deleteItem(transport);
	}
	else
	{
		throw Exceptions(" Deletion error! ");
	}
}

vector<Transport*> Service::getAllTransport()
{
	return repositoryFileTransport->getAll();
}

int Service::getSizeTransport()
{
	return repositoryFileTransport->getSize();
}

Transport* Service::getTransport(int position)
{
	return repositoryFileTransport->getItem(position);
}

int Service::findTransport(Transport* transport)
{
	return repositoryFileTransport->findItem(transport);
}

void Service::addUser(User& user)
{
	repositoryFileUser.addItem(user);
}

void Service::updateUser(User& oldUser, User& newUser)
{
	repositoryFileUser.updateItem(oldUser, newUser);
}

void Service::deleteUser(User& user)
{
	if (repositoryFileUser.findItem(user) != -1)
	{
		repositoryFileUser.deleteItem(user);
	}
	else
	{
		throw Exceptions(" Deletion error! ");
	}
}

vector<User> Service::getAllUser()
{
	return repositoryFileUser.getAll();
}

int Service::getSizeUser()
{
	return repositoryFileUser.getSize();
}

User Service::getUser(int position)
{
	return repositoryFileUser.getItem(position);
}

int Service::findUser(User& user)
{
	return repositoryFileUser.findItem(user);
}

void Service::registration(User& user)
{
	repositoryFileUser.addItem(user);
}

int Service::login(User& user)
{
	int position = repositoryFileUser.findItem(user);
	if (position != -1)
		return position;
	else
		throw Exceptions(" Login error! ");
}

void Service::logout(User& user)
{
	return repositoryFileUser.deleteItem(user);
}

void Service::searchProducator(string producator, Transport* filterTransportsByProducator[], int& lenght)
{
	for (int i = 0; i < this->getSizeTransport(); i++)
	{
		Transport* currentTransport = this->getTransport(i);
		if (currentTransport->getProducator() == producator)
		{
			filterTransportsByProducator[lenght++] = currentTransport;
		}
		else
		{
			throw Exceptions(" Search error! ");
		}
	}
}

void Service::buy(int model, int garnituri_rezervate)
{
	bool ok = 0;
	for (int i = 0; i < this->getSizeTransport(); i++)
	{
		Transport* currentTransport = this->getTransport(i);
		if (currentTransport->getModel() == model)
		{
			ok = 1;
			int numberOfSeatsAvailable = currentTransport->getGarnituri_disponibile() - currentTransport->getGarnituri_rezervate();
			if (numberOfSeatsAvailable >= garnituri_rezervate)
			{
				currentTransport->setGarnituri_rezervate(currentTransport->getGarnituri_rezervate() + garnituri_rezervate);
				Transport* newTransport = currentTransport;
				updateTransport(currentTransport, newTransport);
				if (currentTransport->getGarnituri_disponibile() == currentTransport->getGarnituri_rezervate())
				{
					//fonturi italice
				}
			}
			else
			{
				throw Exceptions(" Buy error! ");
			}
		}
	}
	if (ok == 0)
		throw Exceptions(" Model error! " + model);
}

void Service::remove(int model, int numar_vagoane)
{
	string producator = "";
	int garnituri_disponibile = 0;
	int garnituri_rezervate = 0;
	Transport* transport = new Transport(model, producator, numar_vagoane, garnituri_disponibile, garnituri_rezervate);
	if (repositoryFileTransport->findItem(transport) != -1)
	{
		repositoryFileTransport->deleteItem(transport);
	}
	else
	{
		throw Exceptions(" Deletion error! ");
	}
}