#include "TestRepositoryFileTransport.h"
#include <assert.h>
#include "ValidationException.h"

TestRepositoryFileTransport::TestRepositoryFileTransport()
{
	Marfar* marfar = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	Calatori* calatori = new Calatori(1143, "Intel", 32, 120, 40, 30);
	this->transportsIn.push_back(marfar);
	this->transportsIn.push_back(calatori);
}

TestRepositoryFileTransport::~TestRepositoryFileTransport()
{
}

void TestRepositoryFileTransport::testAddItem()
{

	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	Marfar* marfar = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	try
	{
		repositoryFileTransport->addItem(marfar);
		assert(*repositoryFileTransport->getItem(0) == *marfar->clone());
	}
	catch (ValidationException & exception)
	{
		assert(false);
	}
}

void TestRepositoryFileTransport::testUpdateItem()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	Marfar* marfar1 = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	repositoryFileTransport->addItem(marfar1);
	Marfar* marfar2 = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	Marfar* marfar3 = new Marfar(2300, "Yasuo", 20, "rabadons", 44, 32);
	repositoryFileTransport->updateItem(marfar3, marfar2);
	assert(*repositoryFileTransport->getItem(0) == *marfar1);
	repositoryFileTransport->updateItem(marfar1, marfar2);
	assert(*repositoryFileTransport->getItem(0) == *marfar2);
}

void TestRepositoryFileTransport::testDeleteItem()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	Marfar* marfar1 = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	repositoryFileTransport->addItem(marfar1);
	Marfar* marfar2 = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	repositoryFileTransport->deleteItem(marfar2);
	assert(repositoryFileTransport->getSize() == 1);
	assert(*repositoryFileTransport->getItem(0) == *marfar1);
	repositoryFileTransport->deleteItem(marfar1);
	assert(repositoryFileTransport->getSize() == 0);
}

void TestRepositoryFileTransport::testGetAll()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	Marfar* marfar = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	Calatori* calatori = new Calatori(1143, "Intel", 32, 120, 40, 30);
	repositoryFileTransport->addItem(marfar);
	repositoryFileTransport->addItem(calatori);
	vector<Transport*> transports = repositoryFileTransport->getAll();
	assert(*transports[0] == *marfar->clone());
	assert(*transports[1] == *calatori->clone());
}

void TestRepositoryFileTransport::testGetSize()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	assert(repositoryFileTransport->getSize() == 0);
	repositoryFileTransport->addItem(new Transport());

}

void TestRepositoryFileTransport::testGetItem()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	Marfar* marfar = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	repositoryFileTransport->addItem(marfar);

}

void TestRepositoryFileTransport::testFindItem()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	Marfar* marfar = new Marfar(2343, "Samsung", 20, "baloane", 40, 36);
	repositoryFileTransport->addItem(marfar);
	assert(repositoryFileTransport->findItem(marfar) != -1);
	assert(repositoryFileTransport->findItem(marfar) == 0);
}

void TestRepositoryFileTransport::testLoadFromFileTXT()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT(this->fileNameInTXT, this->fileNameOutTXT, this->validation);
	repositoryFileTransport->loadFromFile();
	assert(repositoryFileTransport->getSize() == this->transportsIn.size());
	assert(*repositoryFileTransport->getItem(0) == *this->transportsIn[0]);
	assert(*repositoryFileTransport->getItem(1) == *this->transportsIn[1]);
}

void TestRepositoryFileTransport::testLoadFromFileCSV()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV(this->fileNameInCSV, this->fileNameOutCSV, this->validation);
	repositoryFileTransport->loadFromFile();
	assert(repositoryFileTransport->getSize() == this->transportsIn.size());
	assert(*repositoryFileTransport->getItem(0) == *this->transportsIn[0]);
	assert(*repositoryFileTransport->getItem(1) == *this->transportsIn[1]);
}

void TestRepositoryFileTransport::testSavetoFileTXT()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT(this->fileNameInTXT, this->fileNameOutTXT, this->validation);
	repositoryFileTransport->loadFromFile();
	Marfar* newMarfar = new Marfar(2300, "Yasuo", 20, "rabadons", 44, 32);
	repositoryFileTransport->addItem(newMarfar);
	repositoryFileTransport->saveToFile();
	repositoryFileTransport->setFileName(this->fileNameOutTXT, this->fileNameOutTXT);
	repositoryFileTransport->loadFromFile();
	assert(repositoryFileTransport->getSize() == this->transportsIn.size() + 1);
	vector<Transport*> transports = repositoryFileTransport->getAll();
	for (int i = 0; i < repositoryFileTransport->getSize() - 1; i++)
	{
		assert(*transports[i] == *this->transportsIn[i]);
	}
	assert(*transports[transports.size() - 1] == *newMarfar);
}

void TestRepositoryFileTransport::testSaveToFileCSV()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV(this->fileNameInCSV, this->fileNameOutCSV, this->validation);
	repositoryFileTransport->loadFromFile();
	Marfar* newMarfar = new Marfar(2300, "Yasuo", 20, "rabadons", 44, 32);
	repositoryFileTransport->addItem(newMarfar);
	repositoryFileTransport->saveToFile();
	repositoryFileTransport->setFileName(this->fileNameOutCSV, this->fileNameOutCSV);
	repositoryFileTransport->loadFromFile();
	assert(repositoryFileTransport->getSize() == this->transportsIn.size() + 1);
	vector<Transport*> transports = repositoryFileTransport->getAll();
	for (int i = 0; i < repositoryFileTransport->getSize() - 1; i++)
	{
		assert(*transports[i] == *this->transportsIn[i]);
	}
	assert(*transports[transports.size() - 1] == *newMarfar);
}

void TestRepositoryFileTransport::runTestRepositoryFileTransport()
{
	this->testAddItem();
	this->testUpdateItem();
	this->testDeleteItem();
	this->testGetAll();
	this->testGetSize();

}