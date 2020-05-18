#pragma once
#include "Transport.h"
#include "Delete1.h"
#include <string>
#include <iostream>

using namespace std;

class Delete2
{
private:
    const char* message;
public:
    Delete2(const char* message) : message(message) {}

    const char* getMessage() { return message; }
};
