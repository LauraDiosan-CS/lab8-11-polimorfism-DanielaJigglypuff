#pragma once
#pragma once
#include "Transport.h"
#include <string>
#include <iostream>

using namespace std;

class Delete1
{
private:
    const char* message;
public:
    Delete1(const char* message) : message(message) {}

    const char* getMessage() { return message; }
};
