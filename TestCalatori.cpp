#include "TestCalatori.h"
#include <assert.h>

TestCalatori::TestCalatori()
{
}

TestCalatori::~TestCalatori()
{
}

void TestCalatori::testImplicitConstructor()
{
	Calatori calatori;
	assert(calatori.getModel() == 0 );
	assert(calatori.getProducator().empty());
	assert(calatori.getNumar_vagoane() == 0);
	assert(calatori.getGarnituri_disponibile() == 0);
	assert(calatori.getGarnituri_rezervate() == 0);
	assert(calatori.getLocuri() == 0);
}

void TestCalatori::testConstructorWithParameters()
{
	Calatori calatori(1143, "Intel", 32, 120, 40, 30);
	assert(calatori.getModel() == 1143);
	assert(calatori.getProducator() == "Intel");
	assert(calatori.getNumar_vagoane() == 32);
	assert(calatori.getGarnituri_disponibile() == 40);
	assert(calatori.getGarnituri_rezervate() == 30);
	assert(calatori.getLocuri() == 120);
}

void TestCalatori::testCopyConstructor()
{
	Calatori calatori1(1143, "Intel", 32, 120, 40, 30);
	Calatori calatori2(calatori1);
	assert(calatori1.getModel() == calatori2.getModel());
	assert(calatori1.getProducator() == calatori2.getProducator());
	assert(calatori1.getNumar_vagoane() == calatori2.getNumar_vagoane());
	assert(calatori1.getGarnituri_disponibile() == calatori2.getGarnituri_disponibile());
	assert(calatori1.getGarnituri_rezervate() == calatori2.getGarnituri_rezervate());
	assert(calatori1.getLocuri() == calatori2.getLocuri());
}

void TestCalatori::testClone()
{
	Calatori calatori(1143, "Intel", 32, 120, 40, 30);
	Calatori* calatoriClone = (Calatori*)calatori.clone();
	assert(calatori == *calatoriClone);
	assert(&calatori != calatoriClone);
}

void TestCalatori::testAssignmentOperator()
{
	Calatori calatori1(1143, "Intel", 32, 120, 40, 30);
	Calatori calatori2(calatori1);
	calatori2 = calatori1;
	assert(calatori1.getModel() == calatori2.getModel());
	assert(calatori1.getProducator() == calatori2.getProducator());
	assert(calatori1.getNumar_vagoane() == calatori2.getNumar_vagoane());
	assert(calatori1.getGarnituri_disponibile() == calatori2.getGarnituri_disponibile());
	assert(calatori1.getGarnituri_rezervate() == calatori1.getGarnituri_rezervate());
	assert(calatori1.getLocuri() == calatori2.getLocuri());
}

void TestCalatori::testEqualityOperator()
{
	Calatori calatori1(1143, "Intel", 32, 120, 40, 30);
	Calatori calatori2 = calatori1;
	assert(calatori1 == calatori2);
	calatori2.setModel(calatori1.getModel());
	assert(calatori1 == calatori2);
	calatori2.setProducator(calatori1.getProducator());
	assert(calatori1 == calatori2);
	calatori2.setNumar_vagoane(calatori1.getNumar_vagoane());
	assert(calatori1 == calatori2);
	calatori2.setGarnituri_disponibile(calatori1.getGarnituri_disponibile());
	assert(calatori1 == calatori2);
	calatori2.setGarnituri_rezervate(calatori1.getGarnituri_rezervate());
	assert(calatori1 == calatori2);
	calatori2.setLocuri(2);
	assert(calatori1 == calatori2);
}

void TestCalatori::testGetLocuri()
{
	Calatori calatori(1143, "Intel", 32, 120, 40, 30);
	assert(calatori.getLocuri() == 120);
}

void TestCalatori::testSettLocuri()
{
	Calatori calatori(1143, "Intel", 32, 120, 40, 30);
	calatori.setLocuri(2);
	assert(calatori.getLocuri() == 2);
}

void TestCalatori::testToString()
{
	Calatori calatori(1143, "Intel", 32, 120, 40, 30);
	assert(calatori.toString(" ") == "Calatori 1143 Intel 32 120 40 30");
	assert(calatori.toString(",") == "Calatori,1143,Intel,32,120,40,36");
}

void TestCalatori::runTestCalatori()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testGetLocuri();
	this->testSettLocuri();
	//this->testToString();
}