#pragma once
#ifndef TEST_TRANSPORT_H
#define TEST_TRANSPORT_H
#include "Transport.h"

class TestTransport
{
private:
	Transport transport;

	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();

	void testClone();

	void testAssignmentOperator();
	void testEqualityOperator();

	void testGetModel();
	void testGetProducator();
	void testGetNumar_vagoane();
	void testGetGarnituri_disponibile();
	void testGetGarnituri_rezervate();

	void testSetModel();
	void testSetProducator();
	void testSetNumar_vagoane();
	void testSetGarnituri_disponibile();
	void testSetGarnituri_rezervate();

	void testToString();
public:
	TestTransport();
	~TestTransport();

	void runTestTransport();
};

#endif 