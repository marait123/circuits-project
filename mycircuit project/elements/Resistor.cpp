#include"Resistor.h"



R::R()
{
	Z.real(0);
	Z.imag(0);
}


R::R(double r)
{
	Z.real(r);
	Z.imag(0);
}

R::~R()
{
}