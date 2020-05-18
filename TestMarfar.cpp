#include "TestMarfar.h"
#include <cassert>

TestMarfar::TestMarfar()
{
}

TestMarfar::~TestMarfar()
{
}

void TestMarfar::testImplicitConstructor()
{
	Marfar marfar;
	assert(marfar.getModel() == 0);
	assert(marfar.getProducator().empty());
	assert(marfar.getNumar_vagoane() == 0);
	assert(marfar.getGarnituri_disponibile() == 0);
	assert(marfar.getGarnituri_rezervate() == 0);
	assert(marfar.getMarfa().empty());
}

void TestMarfar::testConstructorWithParameters()
{
	Marfar marfar(2343, "Marfa", 12, "Baloane", 40, 36);
	assert(marfar.getModel() == 2343);
	assert(marfar.getProducator() == "Marfa");
	assert(marfar.getNumar_vagoane() == 12);
	assert(marfar.getGarnituri_disponibile() == 40);
	assert(marfar.getGarnituri_rezervate() == 36);
	assert(marfar.getMarfa() == "Baloane");
}

void TestMarfar::testCopyConstructor()
{
	Marfar marfar1(2343, "Marfa ", 12, "Baloane", 40, 36);
	Marfar marfar2(marfar1);
	assert(marfar1.getModel() == marfar2.getModel());
	assert(marfar1.getProducator() == marfar2.getProducator());
	assert(marfar1.getNumar_vagoane() == marfar2.getNumar_vagoane());
	assert(marfar1.getGarnituri_disponibile() == marfar2.getGarnituri_disponibile());
	assert(marfar1.getGarnituri_rezervate() == marfar2.getGarnituri_rezervate());
	assert(marfar1.getMarfa() == marfar2.getMarfa());
}

void TestMarfar::testClone()
{
	Marfar marfar(2343, "Marfa ", 12, "Baloane", 40, 36);
	Marfar* marfarClone = (Marfar*)marfar.clone();
	assert(marfar == *marfarClone);
	assert(&marfar != marfarClone);
}

void TestMarfar::testAssignmentOperator()
{
	Marfar marfar1(2343, "Marfa ", 12, "Baloane", 40, 36);
	Marfar marfar2(marfar1);
	marfar2 = marfar1;
	assert(marfar1.getModel() == marfar2.getModel());
	assert(marfar1.getProducator() == marfar2.getProducator());
	assert(marfar1.getNumar_vagoane() == marfar2.getNumar_vagoane());
	assert(marfar1.getGarnituri_disponibile() == marfar2.getGarnituri_disponibile());
	assert(marfar1.getGarnituri_rezervate() == marfar1.getGarnituri_rezervate());
	assert(marfar1.getMarfa() == marfar2.getMarfa());
}

void TestMarfar::testEqualityOperator()
{
	Marfar marfar1(2343, "Marfa ", 12, "Baloane", 40, 36);
	Marfar marfar2 = marfar1;
	assert(marfar1 == marfar2);
	marfar2.setModel(marfar1.getModel());
	assert(marfar1 == marfar2);
	marfar2.setProducator(marfar1.getProducator());
	assert(marfar1 == marfar2);
	marfar2.setNumar_vagoane(marfar1.getNumar_vagoane());
	assert(marfar1 == marfar2);
	marfar2.setGarnituri_disponibile(marfar1.getGarnituri_disponibile());
	assert(marfar1 == marfar2);
	marfar2.setGarnituri_rezervate(marfar1.getGarnituri_rezervate());
	assert(marfar1 == marfar2);
	marfar2.setMarfa("Baloane");
	assert(marfar1 == marfar2);
}

void TestMarfar::testGetMarfa()
{
	Marfar marfar(2343, "Marfa ", 12, "Baloane", 40, 36);
	assert(marfar.getMarfa() == "Baloane");
}
void TestMarfar::testSetMarfa()
{
	Marfar marfa;
	marfa.setMarfa("balonase");
	assert(marfa.getMarfa() == "balonase");
}


void TestMarfar::testToString()
{
	Marfar marfar(2343,"Marfa", 12, "Baloane", 40, 36);
	assert(marfar.toString(" ") == "Marfa 2343 Marfa 12 Baloane 40 36");
	assert(marfar.toString(",") == "Marfa,2343,Marfa,12,Baloane,40,36");
}

void TestMarfar::runTestMarfar()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testGetMarfa();
	this->testSetMarfa();
	//this->testToString();
}