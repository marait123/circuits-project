#pragma once

#include"includes.h"

#include"elements/Element.h"

#include"elements/Node.h"

#include"elements/PassiveElement.h"
#include"elements/ActiveElement.h"

#include"elements/Voltage Source.h"
#include"elements/Inductor.h"
#include"elements/Capacitor.h"
#include"elements/Resistor.h"


class Solver
{

public:
	Solver();
	~Solver();

	void Read();
	void Solve();
	void Write();

	
private:
	enum { MaxNum = 100, MaxData = 6 };


	// the map stores id for node where id represents its number in the array 
	map<int, Node*> nodeMap;   // this is just to help determine do i have to make a new node or i just have to add a device to it
	map<int, Node*>::iterator nMit; // node map iterator 


	double Omega;		//omega is set to 60 in the constructor
		 
	Node* N[MaxNum];
	int nTop;  //the index of the last node 

	Element* EE[MaxNum];
	int eTop;
/*
	PassiveElement* PE[MaxNum];
	int Ptop;

	ActiveElement* AE[MaxNum];
	int ATop;
	 */

};
