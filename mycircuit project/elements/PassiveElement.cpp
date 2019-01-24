#include"PassiveElement.h"

PassiveElement::PassiveElement()
{
}

PassiveElement::~PassiveElement()
{
}

  PassiveElement::PassiveElement(complex<double> c) {
	Z = c;

}


void PassiveElement::SetImpedence(complex<double> c) {
	Z = c;

}

complex<double>  PassiveElement::GetImpedence(){

	return Z;
}
 