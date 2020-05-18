#pragma once
#ifndef TEST_BUS_H
#define TEST_BUS_H
#include "Calatori.h"
#include <ostream>

using namespace std;

class TestCalatori
{
private:
	Calatori calatori;

	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();

	void testClone();

	void testAssignmentOperator();
	void testEqualityOperator();

	void testGetLocuri();

	void testSettLocuri();

	void testToString();
public:
	TestCalatori();
	~TestCalatori();

	void runTestCalatori();
};

#endif 