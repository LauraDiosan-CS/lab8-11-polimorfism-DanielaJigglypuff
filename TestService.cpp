#include "Service.h"
#include "TestService.h"
#include "ValidationMarfar.h"
#include "ValidationCalatori.h"
#include "Exceptions.h"
#include <cassert>

TestService::TestService()
{
	ValidationTransport* validationMarfar = new ValidationMarfar();
	ValidationTransport* validationCalatori = new ValidationCalatori();
	Transport* marfar = new Marfar(2343, "Samsung",20 , "baloane", 40, 36);
	Transport* calatori = new Calatori(1143, "Intel", 32, 120, 40, 30);
	this->transportsIn.push_back(marfar);
	this->transportsIn.push_back(calatori);
}

TestService::~TestService()
{
}

void TestService::testAddTransport()
{
	ValidationTransport* validationMarfar = new ValidationMarfar();
	ValidationTransport* validationCalatori = new ValidationCalatori();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	Transport* marfar = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	try
	{
		service->addTransport(marfar);
		assert(*service->getTransport(0) == *marfar);
	}
	catch (Exceptions & exception)
	{
		assert(false);
	}
}

void TestService::testUpdateTransport()
{
	ValidationTransport* validationMarfar = new ValidationMarfar();
	ValidationTransport* validationCalatori = new ValidationCalatori();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	Transport* marfar1 = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	service->addTransport(marfar1);
	Transport* marfar2 = new Marfar(2300, "Yasuo", 20, "rabadons", 44, 32);
	Transport* marfar3 = new Marfar(1200, "Irelia", 20, "fantomite", 14, 2);
	service->updateTransport(marfar3, marfar2);
	assert(*service->getTransport(0) == *marfar1);
	service->updateTransport(marfar1, marfar2);
	assert(*service->getTransport(0) == *marfar2);
}

void TestService::testDeleteTransport()
{
	ValidationTransport* validationMarfar = new ValidationMarfar();
	ValidationTransport* validationCalatori = new ValidationCalatori();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	Transport* marfar1 = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	service->addTransport(marfar1);
	Transport* marfar2 = new Marfar(2300, "Yasuo", 20, "rabadons", 44, 32);
	if(service->findTransport(marfar2) != -1)
		service->deleteTransport(marfar2);
	assert(service->getSizeTransport() == 1);
	assert(*service->getTransport(0) == *marfar1);
	if(service->findTransport(marfar1) != -1)
		service->deleteTransport(marfar1);
	assert(service->getSizeTransport() == 0);
}

void TestService::testGetAllTransport()
{
	ValidationTransport* validationMarfar = new ValidationMarfar();
	ValidationTransport* validationCalatori = new ValidationCalatori();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	Transport* marfar = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	Transport* calatori = new Calatori(1143, "Intel", 32, 120, 40, 30);
	service->addTransport(marfar);
	service->addTransport(calatori);
	vector<Transport*> transports = service->getAllTransport();
	assert(*transports[0] == *marfar->clone());
	assert(*transports[1] == *calatori->clone());
}

void TestService::testGetSizeTransport()
{
	ValidationTransport* validationMarfar = new ValidationMarfar();
	ValidationTransport* validationCalatori = new ValidationCalatori();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	assert(service->getSizeTransport() == 0);
	service->addTransport(new Transport());
	assert(service->getSizeTransport() == 1);
}

void TestService::testGetTransport()
{
	ValidationTransport* validationMarfar = new ValidationMarfar();
	ValidationTransport* validationCalatori = new ValidationCalatori();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	Transport* marfar = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	service->addTransport(marfar);
	assert(*service->getTransport(0) == *marfar->clone());
	assert(*service->getTransport(-1) == *(new Transport()));
	assert(*service->getTransport(1) == *(new Transport()));
}

void TestService::testFindTransport()
{
	ValidationTransport* validationMarfar = new ValidationMarfar();
	ValidationTransport* validationCalatori = new ValidationCalatori();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	Transport* marfar = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	service->addTransport(marfar);
	assert(service->findTransport(marfar) != -1);
	assert(service->findTransport(marfar) == 0);
}

void TestService::testAddUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	User user("irina14", "ai2000");
	service->addUser(user);
	assert(service->getUser(0) == user);
}

void TestService::testUpdateUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	User user1("irina14", "ai2000");
	service->addUser(user1);
	User user2("teodor.pop2008", "bw2008");
	assert(service->getUser(0) == user1);
	service->updateUser(user1, user2);
	assert(service->getUser(0) == user2);
}

void TestService::testDeleteUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	User user1("irina14", "ai2000");
	service->addUser(user1);
	User user2("teodor.pop2008", "bw2008");
	if(service->findUser(user2) != -1)
		service->deleteUser(user2);
	assert(service->getSizeUser() == 1);
	assert(service->getUser(0) == user1);
	service->deleteUser(user1);
	assert(service->getSizeUser() == 0);
}

void TestService::testGetAllUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	User user("irina14", "ai2000");
	service->addUser(user);
	vector<User> users = service->getAllUser();
	assert(users[0] == user);
}

void TestService::testGetSizeUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	assert(service->getSizeUser() == 0);
}

void TestService::testGetUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	User user1("irina14", "ai2000");
	service->addUser(user1);
	assert(service->getUser(0) == user1);
	User user2("teodor.pop2008", "bw2008");
	service->addUser(user2);
	assert(service->getUser(1) == user2);
}

void TestService::testFindUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	User user("irina14", "ai2000");
	service->addUser(user);
	assert(service->findUser(user) != -1);
	assert(service->findUser(user) == 0);
}

void TestService::testRegistration()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	User user("irina14", "ai2000");
	service->registration(user);
	assert(repositoryFileUser.findItem(user));
}

void TestService::testLogin()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	User user("irina14", "ai2000");
	if(service->findUser(user) != -1)
		service->login(user);
	assert(repositoryFileUser.findItem(user));
}

void TestService::testLogout()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	User user("irina14", "ai2000");
	service->logout(user);
	assert(repositoryFileUser.findItem(user) == -1);
}

void TestService::testSearch()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	Transport* filterTransportsByProducator[100];
	string producator = "Samsung";
	int lenght = 0, i;
	service->searchProducator(producator, filterTransportsByProducator, lenght);
	for (i = 0; i < lenght; i++)
	{
		assert(filterTransportsByProducator[i]->getProducator() == "Samsung");
	}
}

void TestService::testBuy()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	int model = 2343;
	int garnituri_rezervate = 3, i;
	service->buy(model, garnituri_rezervate);
	for (i = 0; i < service->getSizeTransport(); i++)
	{
		if (service->getTransport(i)->getModel() == 2343)
		{
			assert(service->getTransport(i)->getGarnituri_rezervate() == 1);
		}
	}
}

void TestService::runTestService()
{
	this->testAddTransport();
	this->testUpdateTransport();
	this->testDeleteTransport();
	this->testGetAllTransport();
	this->testGetSizeTransport();
	this->testGetTransport();
	this->testFindTransport();
	this->testAddUser();
	this->testUpdateUser();
	this->testDeleteUser();
	this->testGetAllUser();
	this->testGetSizeUser();
	this->testGetUser();
	this->testFindUser();
	this->testRegistration();
	this->testLogin();
	this->testLogout();
	this->testSearch();
	this->testBuy();
}