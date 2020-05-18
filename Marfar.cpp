#include "Marfar.h"
#include <string>

Marfar::Marfar() : Transport()
{

}

Marfar::Marfar(int model, string producator, int numar_vagoane, string marfa, int garnituri_disponibile, int garnituri_rezervate) : Transport(model, producator, numar_vagoane, garnituri_disponibile, garnituri_rezervate)
{
	this->marfa = marfa;
}

Marfar::Marfar(const Marfar& marfar) : Transport(marfar)
{
	this->marfa = marfar.marfa;
}

Marfar::~Marfar()
{
}

Transport* Marfar::clone()
{
	return new Marfar(this->model, this->producator, this->numar_vagoane, this->marfa, this->garnituri_disponibile, this->garnituri_rezervate);
}

Marfar& Marfar::operator=(const Marfar& marfar)
{
	Transport::operator=(marfar);
	this->marfa = marfar.marfa;
	return *this;
}

bool Marfar::operator==(const Marfar& marfar)
{
	return Transport::operator==(marfar);
}

string Marfar::getMarfa()
{
	return this->marfa;
}

void Marfar::setMarfa(string marfa)
{
	this->marfa = marfa;
}

string Marfar::toString(string delimiter)
{
	return "Marfar" + delimiter + Transport::toString(delimiter) + delimiter + this->marfa;
}