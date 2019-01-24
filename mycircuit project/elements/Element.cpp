
#include"Element.h"

Element::Element()
{
	N[0] = NULL;
	N[1] = NULL;
}


Element::~Element()
{
}
void Element::SetImpedence(complex<double> im){
	Z = im;

}

complex<double> Element::GetImpedence(){
	return Z;

}

void Element::SetVolt(complex<double> vv) {
	this->Volt = vv;

}

complex<double>Element::GetVolt() {

	return this->Volt;
}


void Element::SetCurr(complex<double> vv) {
	this->Curr = vv;

}

complex<double>Element::GetCurr() {

	return this->Curr;
}



void Element::SetNode1(Node* node) {

	N[0] = node;

}
Node* Element::GetNode1(){
	return N[0];
}

void Element::SetNode2(Node* node){
	N[1] = node;
}

Node* Element::GetNode2() {
	return N[1];

}


void Element::Write(ofstream& sOut) {

	double phAng = arg(this->Curr);  // phase angle 
	double mag = abs(this->Curr);



	sOut<< "I (" <<N[0]->GetId() << " "<<N[1]->GetId() <<") " << mag << " " << phAng * 180 / pi;

}
