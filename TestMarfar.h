#pragma once
#ifndef TEST_AIR_PLANE_H
#define TEST_AIR_PLANE_H
#include "Marfar.h"

class TestMarfar
{
private:
	Marfar marfar;

	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();

	void testClone();

	void testAssignmentOperator();
	void testEqualityOperator();

	void testGetMarfa();

	void testSetMarfa();

	void testToString();
public:
	TestMarfar();
	~TestMarfar();

	void runTestMarfar();
};

#endif 