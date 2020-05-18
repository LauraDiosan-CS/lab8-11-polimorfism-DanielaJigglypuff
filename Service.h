#pragma once
#ifndef SERVICE_H
#define SERVICE_H
#include "Transport.h"
#include "Marfar.h"
#include "Calatori.h"
#include "RepositoryFileTransport.h"
#include "RepositoryFileCSV.h"
#include "RepositoryFileTXT.h"
#include "User.h"
#include "RepositoryFileUser.h"
#include "ValidationTransport.h"

class Service
{
private:
	RepositoryFileTransport* repositoryFileTransport;
	RepositoryFileUser repositoryFileUser;

	ValidationTransport* validation;
public:
	Service(ValidationTransport* validation);
	Service(RepositoryFileTransport* repositoryFileTransport, RepositoryFileUser repositoryFileUser);
	~Service();

	void setRepository(RepositoryFileTransport* repositoryFileTransport, RepositoryFileUser repositoryFileUser);

	void addTransport(Transport* transport);
	void updateTransport(Transport* oldTransport, Transport* newTransport);
	void deleteTransport(Transport* transport);
	vector<Transport*> getAllTransport();
	int getSizeTransport();
	Transport* getTransport(int position);
	int findTransport(Transport* transport);

	void addUser(User& user);
	void updateUser(User& oldUser, User& newUser);
	void deleteUser(User& user);
	vector<User> getAllUser();
	int getSizeUser();
	User getUser(int position);
	int findUser(User& user);

	void registration(User& user);
	int login(User& user);
	void logout(User& user);

	void searchProducator( string producator , Transport* filterTransportsByProducator[], int& lenght);
	void buy(int model, int garnituri_rezervate);

	void remove(int, int);
};
#endif