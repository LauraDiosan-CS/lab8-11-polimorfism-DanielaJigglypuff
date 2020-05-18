#pragma once
#ifndef DOMAIN_DERIVED_1_H
#define DOMAIN_DERIVED_1_H
#include "Transport.h"

class Marfar : public Transport
{
private:
   string marfa;
public:
    Marfar();
    Marfar(int model, string producator, int numar_vagoane, string marfa, int garnituri_disponibile, int garnituri_rezervate);
    Marfar(const Marfar& transport);
    ~Marfar();

    Transport* clone();

    Marfar& operator = (const Marfar& marfar);
    bool operator == (const Marfar& marfar);

    string getMarfa();

    void setMarfa(string marfa);

    string toString(string delimiter);
};

#endif 