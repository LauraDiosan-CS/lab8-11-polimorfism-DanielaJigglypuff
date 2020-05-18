#pragma once
#ifndef VALIDATION_BUS_H
#define VALIDATION_BUS_H
#include "Calatori.h"
#include "ValidationTransport.h"

class ValidationCalatori : public ValidationTransport
{
private:
    int errors;
    string message;
public:
    ValidationCalatori();
    ~ValidationCalatori();

    int validate(Transport*);
};

#endif