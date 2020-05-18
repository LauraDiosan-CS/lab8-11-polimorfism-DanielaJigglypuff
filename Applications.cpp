#include <iostream>
#include "UserInterface.h"
#include "ValidationMarfar.h"
#include "ValidationCalatori.h"
#include "Exceptions.h"
#include "TestTransport.h"
#include "TestMarfar.h"
#include "TestCalatori.h"
#include "TestUser.h"
#include "Tests.h"


using namespace std;

int main()
{
	
	TestTransport testTransport;
	testTransport.runTestTransport();

	TestMarfar testMarfar;
	testMarfar.runTestMarfar();

	TestCalatori testCalatori;
	testCalatori.runTestCalatori();

	TestUser testUser;
	testUser.runTestUser();

	Tests tests;
	tests.runTests();

	Exceptions exception();

	ValidationTransport* validationMarfar = new ValidationMarfar();
	ValidationTransport* validationCalatori = new ValidationCalatori();

	UserInterface ui;
	ui.run();

	delete validationMarfar;
	delete validationCalatori;

	return 0;
}