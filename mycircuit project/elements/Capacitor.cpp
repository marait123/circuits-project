#include"Capacitor.h"


C::C() {
	
}


C::C(double capa) {  // stands for capacitance 
	Z.real(0);
	Z.imag(double(-1) / (OMEGA*capa));		// note you can multiply complex double by double only 
	
}

C::~C() {

}
