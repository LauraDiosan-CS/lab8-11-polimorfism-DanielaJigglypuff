#pragma once
#ifndef VALIDATION_AIR_PLANE_H
#define VALIDATION_AIR_PLANE_H
#include "Marfar.h"
#include "ValidationTransport.h"

class ValidationMarfar : public ValidationTransport
{
private:
    int errors;
    string message;
public:
    ValidationMarfar();
    ~ValidationMarfar();

    int validate(Transport*);
};

#endif