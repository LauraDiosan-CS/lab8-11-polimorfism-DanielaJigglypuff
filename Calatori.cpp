#include "Calatori.h"
#include <string>

Calatori::Calatori() : Transport()
{
	this->locuri = 0;
}

Calatori::Calatori(int model, string producator, int numar_vagoane, int locuri, int garnituri_disponibile, int garnituri_rezervate) : Transport(model, producator, numar_vagoane,  garnituri_disponibile, garnituri_rezervate)
{
	this->locuri = locuri;
}

Calatori::Calatori(const Calatori& calatori) : Transport(calatori)
{
	this->locuri = calatori.locuri;
}

Calatori::~Calatori()
{
}

Transport* Calatori::clone()
{
	return new Calatori(this->model, this->producator, this->numar_vagoane, this->locuri, this->garnituri_disponibile, this->garnituri_rezervate);
}

Calatori& Calatori::operator=(const Calatori& calatori)
{
	Transport::operator=(calatori);
	this->locuri = calatori.locuri;
	return *this;
}

bool Calatori::operator==(const Calatori& calatori)
{
	return this->Transport::operator==(calatori);
}

int Calatori::getLocuri()
{
	return this->locuri;
}

void Calatori::setLocuri(int locuri)
{
	this->locuri = locuri;
}

string Calatori::toString(string delimiter)
{
	return "Calatori" + delimiter + Transport::toString(delimiter) + delimiter + to_string(locuri);
}