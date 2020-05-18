#pragma once
#ifndef DOMAIN_DERIVED_2_H
#define DOMAIN_DERIVED_2_H
#include "Transport.h"

class Calatori : public Transport
{
private:
    int locuri;
public:
    Calatori();
    Calatori(int model, string producator, int numar_vagoane, int locuri, int garnituri_disponibile, int garnituri_rezervate);
    Calatori(const Calatori& transport);
    ~Calatori();

    Transport* clone();

    Calatori& operator = (const Calatori& marfar);
    bool operator == (const Calatori& marfar);

    int getLocuri();

    void setLocuri(int locuri);

    string toString(string delimiter);
};

#endif 