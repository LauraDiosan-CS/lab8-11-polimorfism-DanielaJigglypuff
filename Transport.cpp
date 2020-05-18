#include "Transport.h"
#include <string>

Transport::Transport()
{
	this->model = 0;
	this->numar_vagoane = 0;
	this->garnituri_disponibile = 0;
	this->garnituri_rezervate = 0;
}

Transport::Transport(int model, string producator, int numar_vagoane,  int garnituri_disponibile, int garnituri_rezervate)
{
	this->model = model;
	this->producator = producator;
	this->numar_vagoane = numar_vagoane;
	this->garnituri_disponibile = garnituri_disponibile;
	this->garnituri_rezervate = garnituri_rezervate;
}

Transport::Transport(const Transport& transport)
{
	this->model = transport.model;
	this->producator = transport.producator;
	this->numar_vagoane = transport.numar_vagoane;
	this->garnituri_disponibile = transport.garnituri_disponibile;
	this->garnituri_rezervate = transport.garnituri_rezervate;
}

Transport::~Transport()
{
}

Transport* Transport::clone()
{
	return new Transport(this->model, this->producator, this->numar_vagoane, this->garnituri_disponibile, this->garnituri_rezervate);
}

Transport& Transport::operator=(const Transport& transport)
{
	this->model = transport.model;
	this->producator = transport.producator;
	this->numar_vagoane = transport.numar_vagoane;
	this->garnituri_disponibile = transport.garnituri_disponibile;
	this->garnituri_rezervate = transport.garnituri_rezervate;
	return *this;
}

bool Transport::operator==(const Transport& transport)
{
	return (model == transport.model);
}

int Transport::getModel()
{
	return this->model;
}

string Transport::getProducator()
{
	return this->producator;
}

int Transport::getNumar_vagoane()
{
	return this->numar_vagoane;
}


int Transport::getGarnituri_disponibile()
{
	return this->garnituri_disponibile;
}

int Transport::getGarnituri_rezervate()
{
	return this->garnituri_rezervate;
}

void Transport::setModel(int model)
{
	this->model = model;
}

void Transport::setProducator(string producator)
{
	this->producator = producator;
}

void Transport::setNumar_vagoane(int numar_vagoane)
{
	this->numar_vagoane = numar_vagoane;
}

void Transport::setGarnituri_disponibile(int garnituri_disponibile)
{
	this->garnituri_disponibile = garnituri_disponibile;
}

void Transport::setGarnituri_rezervate(int garnituri_rezervate)
{
	this->garnituri_rezervate = garnituri_rezervate;
}

string Transport::toString(string delimiter)
{
	return to_string(this->model)+ delimiter + this->producator + delimiter + to_string(this->numar_vagoane) + delimiter + to_string(this->garnituri_disponibile) + delimiter + to_string(this->garnituri_rezervate);
}