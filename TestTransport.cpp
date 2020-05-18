#include "TestTransport.h"
#include <assert.h>

TestTransport::TestTransport()
{
}

TestTransport::~TestTransport()
{
}

void TestTransport::testImplicitConstructor()
{
	Transport transport;
	assert(transport.getModel() == 0);
	assert(transport.getProducator().empty());
	assert(transport.getNumar_vagoane() == 0);
	assert(transport.getGarnituri_disponibile() == 0);
	assert(transport.getGarnituri_rezervate() == 0);
}

void TestTransport::testConstructorWithParameters()
{
	Transport transport(1234, "Lulu" , 12, 40, 36);
	assert(transport.getModel() == 1234);
	assert(transport.getProducator() == "Lulu");
	assert(transport.getNumar_vagoane() == 12);
	assert(transport.getGarnituri_disponibile() == 40);
	assert(transport.getGarnituri_rezervate() == 36);
}

void TestTransport::testCopyConstructor()
{
	Transport transport1(1234, "Lulu" , 12, 40, 36);
	Transport transport2(transport1);
	assert(transport1.getModel() == transport2.getModel());
	assert(transport1.getProducator() == transport2.getProducator());
	assert(transport1.getNumar_vagoane() == transport2.getNumar_vagoane());
	assert(transport1.getGarnituri_disponibile() == transport2.getGarnituri_disponibile());
	assert(transport1.getGarnituri_rezervate() == transport2.getGarnituri_rezervate());
}

void TestTransport::testClone()
{
	Transport transport(1234, "Lulu" , 12, 40, 36);
	Transport* cloneTransport = transport.clone();
	assert(transport == *cloneTransport);
	assert(&transport != cloneTransport);
}

void TestTransport::testAssignmentOperator()
{
	Transport transport1(1234, "Lulu" , 12, 40, 36);
	Transport transport2(transport);
	transport2 = transport1;
	assert(transport1.getModel() == transport2.getModel());
	assert(transport1.getProducator() == transport2.getProducator());
	assert(transport1.getNumar_vagoane() == transport2.getNumar_vagoane());
	assert(transport1.getGarnituri_disponibile() == transport2.getGarnituri_disponibile());
	assert(transport1.getGarnituri_rezervate() == transport1.getGarnituri_rezervate());
}

void TestTransport::testEqualityOperator()
{
	Transport transport1(1234, "Lulu" , 12, 40, 36);
	Transport transport2 = transport1;
	assert(transport1 == transport2);
	transport2.setModel(transport1.getModel());
	assert(transport1 == transport2);
	transport2.setProducator(transport1.getProducator());
	assert(transport1 == transport2);
	transport2.setNumar_vagoane(transport1.getNumar_vagoane());
	assert(transport1 == transport2);
	transport2.setGarnituri_disponibile(transport1.getGarnituri_disponibile());
	assert(transport1 == transport2);
	transport2.setGarnituri_rezervate(transport1.getGarnituri_rezervate());
	assert(transport1 == transport2);
}

void TestTransport::testGetModel()
{
	Transport transport(1234, "Lulu" , 12, 40, 36);
	assert(transport.getModel() == 1234 );
}

void TestTransport::testGetProducator()
{
	Transport transport(1234, "Lulu" , 12, 40, 36);
	assert(transport.getProducator() == "Lulu");
}
void TestTransport::testGetNumar_vagoane()
{
	Transport transport(1234, "Lulu", 12, 40, 36);
	assert(transport.getNumar_vagoane() == 12);
}

void TestTransport::testGetGarnituri_disponibile()
{
	Transport transport(1234, "Lulu" , 12, 40, 36);
	assert(transport.getGarnituri_disponibile() == 40);
}

void TestTransport::testGetGarnituri_rezervate()
{
	Transport transport(1234, "Lulu" , 12, 40, 36);
	assert(transport.getGarnituri_rezervate() == 36);
}

void TestTransport::testSetModel()
{
	Transport transport;
	transport.setModel(8888);
	assert(transport.getModel() == 8888);
}

void TestTransport::testSetProducator()
{
	Transport transport;
	transport.setProducator("SuperMario");
	assert(transport.getProducator() == "SuperMario");
}


void TestTransport::testSetNumar_vagoane()
{
	Transport transport;
	transport.setNumar_vagoane(12);
	assert(transport.getNumar_vagoane() == 12);
}

void TestTransport::testSetGarnituri_disponibile()
{
	Transport transport;
	transport.setGarnituri_disponibile(40);
	assert(transport.getGarnituri_disponibile() == 40);
}

void TestTransport::testSetGarnituri_rezervate()
{
	Transport transport;
	transport.setGarnituri_rezervate(36);
	assert(transport.getGarnituri_rezervate() == 36);
}

void TestTransport::testToString()
{
	Transport transport(1234, "Lulu" , 12, 40, 36);
	assert(transport.toString(" ") == "1234 Lulu 12 40 36");
	assert(transport.toString(",") == "1234,Lulu,12,40,36");
}

void TestTransport::runTestTransport()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testGetModel();
	this->testGetProducator();
	this->testGetNumar_vagoane();
	this->testGetGarnituri_disponibile();
	this->testGetGarnituri_rezervate();
	this->testSetModel();
	this->testSetProducator();
	this->testSetNumar_vagoane();	
	this->testSetGarnituri_disponibile();
	this->testSetGarnituri_rezervate();
	this->testToString();
}