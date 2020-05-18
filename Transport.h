#pragma once
#ifndef DOMAIN_BASE_H
#define DOMAIN_BASE_H
#include <string>

using namespace std;

class Transport
{
protected:
    int model;
    string producator;
    int numar_vagoane;
    int garnituri_disponibile;
    int garnituri_rezervate;
public:
    Transport();
    Transport(int model, string producator, int numar_vagoane, int garnituri_disponibile, int garnituri_rezervate);
    Transport(const Transport& transport);
    ~Transport();

    virtual Transport* clone();

    Transport& operator = (const Transport& transport);
    bool operator == (const Transport& transport);

    int getModel();
    string getProducator();
    int getNumar_vagoane();
    int getGarnituri_disponibile();
    int getGarnituri_rezervate();

    void setModel(int model);
    void setProducator(string producator);
    void setNumar_vagoane(int numar_vagoane);
    void setGarnituri_disponibile(int garnituri_disponibile);
    void setGarnituri_rezervate(int garnituri_rezervate);

    virtual string toString(string delimiter);
};

#endif 