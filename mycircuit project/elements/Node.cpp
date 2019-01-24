#include"Node.h"

Node::Node()
{
	id = -1; //means no id is set
	lastElment = 0;

}

Node::Node(int ID)
{
	id = ID; //means no id is set
	lastElment = 0;
	this->nodePol = Polarity::Pos;

}


Node::Node(int ID,complex<double> vo)
{
	id = ID;
	vo = 0;
	lastElment = 0;

}

Node::Node(int I_D, Polarity p) {
	id = I_D;
	this->nodePol = p;
	lastElment = 0;

}
 
Node::~Node()
{
}


void Node::SetVolt(complex<double> vo){
	V = vo;
}
 
complex<double> Node::GetVolt() {

	return V;
}

void Node::AddElemnt(Element* ele) {
	eleArr[lastElment++] = ele;
}


int Node::GetId(){
	return this->id;
}

void Node::SetId(int i_d){
	this->id =  i_d; 
}


Polarity Node::GetPol() {
	return this->nodePol;
}

void Node::SetPol(Polarity p){
	this->nodePol = p;

}

void Node::Write(ofstream& sOut){

	double phAng = arg(this->V);  // phase angle 
	double mag = abs(this->V);

	sOut << "V(" << this->id << ") " << mag << " " << phAng * 180 / pi ;

}
