#include "UserInterface.h"
#include "Transport.h"
#include "Marfar.h"
#include "Calatori.h"
#include "User.h"
#include "ValidationException.h"
#include "Exceptions.h"
#include <iostream>

UserInterface::UserInterface()
{
	okFile = 0;
	okUserName ="";
	okPassword = "";
	validation = new ValidationTransport();
}

UserInterface::UserInterface(Service* service)
{
	this->service = service;
	validation = new ValidationTransport();
}

UserInterface::~UserInterface()
{
}

void UserInterface::setService(Service* service)
{
	this->service = service;
}

void UserInterface::readFileTXT()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT(this->fileNameInTXT, this->fileNameOutTXT, this->validation);
	RepositoryFileUser repositoryFileUser(this->fileNameIn, this->fileNameOut);
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	this->setService(service);
	okFile = 0;

}

void UserInterface::readFileCSV()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV(this->fileNameOutCSV, this->fileNameOutCSV, this->validation);
	RepositoryFileUser repositoryFileUser(this->fileNameIn, this->fileNameOut);
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	this->setService(service);
	okFile = 1;
}

void UserInterface::registration()
{
	string userName;
	cout << " Enter the user name: ";
	cin >> userName;
	string password;
	cout << " Enter the password: ";
	cin >> password;
	string confirmPassword;
	cout << " Confirm password: ";
	cin >> confirmPassword;
	if (password == confirmPassword)
	{
		User user(userName, password);
		service->registration(user);
		cout << endl << " The user was added!";
	}
	else
	{
		cout << endl <<" Registration failed! ";
		
	}
}

void UserInterface::login() 
{
	string userName;
	cout << " Enter the user name: ";
	cin >> userName;
	okUserName = userName;
	string password;
	cout << " Enter the password: ";
	cin >> password;
	okPassword = password;
	User user(userName, password);
	try
	{
		if (service->login(user) != -1)
		{
			runOperations();
		}
	}
	catch(Exceptions & exception)
	{
		cout << endl << " Exception: " << exception.getMessage();
	}
}

void UserInterface::logout()
{
	User user(okUserName, okPassword);
	service->logout(user);
}

void UserInterface::readItem()
{
	showMenuTransports();
	while (true)
	{
		int command;
		cout << " Enter your option: ";
		cin >> command;
		cout << endl;
		int model, numar_vagoane;
		string producator, marfa;
		int garnituri_disponibile, garnituri_rezervate;
		cout << " introduce Modelul: ";
		cin >> model;
		cout << " producator : ";
		cin >> producator;
		cout << " numarul de vagoane: ";
		cin >> numar_vagoane;
		cout << " garnituri disponibile: ";
		cin >> garnituri_disponibile;
		cout << " garnituri rezervate : ";
		cin >> garnituri_rezervate;
		if (command == 0)
		{
			break;
		}
		if (command == 1)
		{
			string marfa;
			cout << " marfa ? ";
			cin >> marfa;
			Marfar* marfar = new Marfar( model, producator, numar_vagoane, marfa, garnituri_disponibile, garnituri_rezervate);
		}
		if (command == 2)
		{
			int locuri;
			cout << " introduce locurile: ";
			cin >> locuri;
			Calatori* calatori = new Calatori(model, producator, numar_vagoane, locuri, garnituri_disponibile, garnituri_rezervate);
		}
	}
}

void UserInterface::updateItem()
{
	showMenuTransports();
	while (true)
	{
		int command;
		cout << " Enter your option: ";
		cin >> command;
		cout << endl;
		int model,numar_vagoane = 0;
		string producator = "";
		int garnituri_disponibile = 0, garnituri_rezervate = 0, locuri = 0;
		string marfa = 0;
		if (command == 0)
		{
			break;
		}
		if (command == 1)
		{
			cout << " Enter the model of air plane you want to update: ";
			cin >> model;
			Marfar* oldMarfar = new Marfar(model, producator, numar_vagoane, marfa, garnituri_disponibile, garnituri_rezervate);
			cout << endl << " Enter the new transport! " << endl;
			cout << " introduce Modelul: ";
			cin >> model;
			cout << " producator : ";
			cin >> producator;
			cout << " numarul de vagoane: ";
			cin >> numar_vagoane;
			cout << " garnituri disponibile: ";
			cin >> garnituri_disponibile;
			cout << " garnituri rezervate : ";
			cin >> garnituri_rezervate;
			cout << " marfa ?  ";
			cin >> marfa;
			Marfar* newMarfar = new Marfar(model, producator, numar_vagoane, marfa, garnituri_disponibile, garnituri_rezervate);
			try
			{
				service->updateTransport(oldMarfar, newMarfar);
				cout << endl << " The transport was updated! " << endl;
			}
			catch (Exceptions & exception)
			{
				cout << "Exception:" << exception.getMessage();
			}
		}
		if (command == 2)
		{
			cout << " Enter the model of calatori you want to update: ";
			cin >> model;
			Calatori* oldCalatori = new Calatori(model, producator, numar_vagoane, locuri, garnituri_disponibile, garnituri_rezervate);
			cout << endl << " Enter the new transport! ";
			
			cout << " introduce Modelul: ";
			cin >> model;
			cout << " producator : ";
			cin >> producator;
			cout << " numarul de vagoane: ";
			cin >> numar_vagoane;
			cout << " garnituri disponibile: ";
			cin >> garnituri_disponibile;
			cout << " garnituri rezervate : ";
			cin >> garnituri_rezervate;
			cout << "  locurile ?";
			cin >> locuri;
		
			Calatori* newCalatori = new Calatori(model, producator, numar_vagoane, locuri, garnituri_disponibile, garnituri_rezervate);
			try
			{
				service->updateTransport(oldCalatori, newCalatori);
				cout << endl << " The transport was updated! " << endl;
			}
			catch (Exceptions & exception)
			{
				cout << "Exception:" << exception.getMessage();
			}
		}
	}
}

void UserInterface::deleteItem()
{
	int model = 0; string producator = "";
	int numar_vagoane = 0;
	int garnituri_disponibile = 0, garnituri_rezervate = 0;
	cout << " Enter the model of transport you want to delete: ";
	cin >> model;
	Transport* transport = new Transport(model, producator, numar_vagoane, garnituri_disponibile, garnituri_rezervate);
	try
	{
		service->deleteTransport(transport);
		cout << endl << " The transport was deleted! " << endl;
	}
	catch (Exceptions & exception)
	{
		cout << endl << " Exception: " << exception.getMessage();
	}
}

void UserInterface::showAll()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<Transport*> transports = service->getAllTransport();
	if (okFile == 0)
	{
		for (Transport* transport : transports)
		{
			if (transport->getGarnituri_disponibile() == transport->getGarnituri_rezervate())
			{
				SetConsoleTextAttribute(h, 12);
				cout << transport->toString(" ") << endl;
				SetConsoleTextAttribute(h, 15);
			}
			else
				cout << transport->toString(" ") << endl;
		}
	}
	if (okFile == 1)
	{
		for (Transport* transports : service->getAllTransport())
		{
			cout << transports->toString(",") << endl;
		}
	}
}

void UserInterface::searchProducator()
{
	string producator;
	cout << " Insert the  you want to searchProducator: ";
	cin >> producator;
	Transport* filterTransportByProducator[100]{};
	int lenght = 0, i;
	try
	{
		if (okFile == 0)
		{
			service->searchProducator(producator, filterTransportByProducator, lenght);
			for (i = 0; i < lenght; i++)
			{
				cout << filterTransportByProducator[i]->toString(" ") << endl;
			}
		}
		if (okFile == 1)
		{
			service->searchProducator(producator, filterTransportByProducator, lenght);
			for (i = 0; i < lenght; i++)
			{
				cout << filterTransportByProducator[i]->toString(",") << endl;
			}
		}
	}
	catch (Exceptions& exception)
	{
		cout << endl << " Exception: " << exception.getMessage();
	}
}

void UserInterface::buy()
{
	int model;
	cout << " modelul : ";
	cin >> model;
	int garnituri_rezervate;
	cout << " numarul de garnituri : ";
	cin >> garnituri_rezervate;
	try
	{
		service->buy(model, garnituri_rezervate);
		cout << endl << " garniturile au fost rezervate! " << endl;
	}
	catch (Exceptions& exception)
	{
		cout << endl << " Exception: " << exception.getMessage();
	}
}

void UserInterface::remove()
{
	int model, numar_vagoane;
	cout << " introduce modelul pentru strgere : ";
	cin >> model;
	cout << " numarul de vagoane: ";
	cin >> numar_vagoane;
	try
	{
		service->remove(model, numar_vagoane);
		cout << endl << " The transport was deleted! " << endl;
	}
	catch (Exceptions & exception)
	{
		cout << endl << " Exception: " << exception.getMessage();
	}
}
void UserInterface::showMenuFiles()
{
	cout << endl;
	cout << " 0. Exit " << endl;
	cout << " 1. File TXT " << endl;
	cout << " 2. File CSV " << endl;
	cout << endl;
}

void UserInterface::showMenuUsers()
{
	cout << endl;
	cout << " 0. Exit " << endl;
	cout << " 1. Registration " << endl;
	cout << " 2. Login " << endl;
	cout << " 3. Logout " << endl;
	cout << endl;
}

void UserInterface::showMenuTransports()
{
	cout << endl;
	cout << " 0. Exit " << endl;
	cout << " 1. Marfar " << endl;
	cout << " 2. Calatori " << endl;
	cout << endl;
}

void UserInterface::showMenuOperations()
{
	cout << endl;
	cout << " 0. Exit " << endl;
	cout << " 1. Add " << endl;
	cout << " 2. Show all " << endl;
	cout << " 3. Update " << endl;
	cout << " 4. Delete " << endl;
	cout << " 5. Search " << endl;
	cout << " 6. Buy " << endl;
	cout << " 7. Log Out !  " << endl;
	cout << endl;
}

void UserInterface::runFiles()
{
	while (true)
	{
		showMenuFiles();
		int command;
		cout << " Enter your option: ";
		cin >> command;
		cout << endl;
		if (command == 0)
		{
			break;
		}
		if (command == 1)
		{
			readFileTXT();
			cout << endl;
			break;
		}
		if (command == 2)
		{
			readFileCSV();
			cout << endl;
			break;
		}
	}
}

void UserInterface::runUsers()
{
	UserInterface ui;
	while (true)
	{
		int command;
		showMenuUsers();
		cout << " Enter your option: ";
		cin >> command;
		cout << endl;
		if (command == 0)
		{
			break;
		}
		if (command == 1)
		{
			registration();
			cout << endl;
		}
		if (command == 2)
		{
			login();
			cout << endl;
			break;
		}
		if (command == 3)
		{
			logout();
			cout << endl;
			break;
		}
	}
}

void UserInterface::runOperations()
{
	UserInterface ui;
	while (true)
	{
		showMenuOperations();
		int command;
		cout << " Enter your option: ";
		cin >> command;
		cout << endl;
		if (command == 0)
		{
			break;
		}
		if (command == 1)
		{
			readItem();
			cout << endl;
		}
		if (command == 2)
		{
			showAll();
			cout << endl;
		}
		if (command == 3)
		{
			updateItem();
			cout << endl;
		}
		if (command == 4)
		{
			deleteItem();
			cout << endl;
		}
		if (command == 5)
		{
			searchProducator();
			cout << endl;
		}
		if (command == 6)
		{
			buy();
			cout << endl;
		}
		if (command == 7)
		{
			logout();
			cout << endl;
			cout << " Delogare realizata cu succes ! " << endl;
			ui.runUsers();
		}
	}
}
void UserInterface::run()
{
	
	runFiles();
	runUsers();
}