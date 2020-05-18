#pragma once
#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "Service.h"
#include <Windows.h>
#include <cwchar>

class UserInterface
{
private:
	Service* service;

	const string fileNameInTXT = "TransportsIn.txt";
	const string fileNameOutTXT = "TransportsOut.txt";
	const string fileNameInCSV = "TransportsIn.csv";
	const string fileNameOutCSV = "TransportsOut.csv";
	const string fileNameIn = "UsersIn.txt";
	const string fileNameOut= "UsersOut.txt";

	ValidationTransport* validation;

	bool okFile;
	string okUserName;
	string okPassword;

	void setService(Service* service);

	void readFileTXT();
	void readFileCSV();

	void registration();
	void login();
	void logout();

	void readItem();
	void updateItem();
	void deleteItem();

	void showAll();

	void searchProducator();
	void buy();

	void remove();

	void showMenuFiles();
	void showMenuUsers();
	void showMenuTransports();
	void showMenuOperations();

	void runFiles();
	void runUsers();
	void runOperations();
public:
	UserInterface();
    UserInterface(Service* service);
	~UserInterface();

	void run();
};
#endif