#include"Inductor.h"


L::L()
{
	Z.real(0);
	Z.imag(0);
}

L::L(double indVal)  // the L value of inductor
{
	Z.real(0);
	Z.imag(OMEGA*indVal);
}

L::~L()
{

}

