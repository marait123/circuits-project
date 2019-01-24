#pragma once

#include "../includes.h"


class Element;

class Node
{
public:

	Node();
	Node(int);
	Node(int, complex<double> );
	Node(int, Polarity );


	~Node();
	Polarity GetPol();
	void SetPol(Polarity);

	void SetVolt(complex<double>);
	complex<double> GetVolt();
	void AddElemnt(Element*);

	int GetId();
	void SetId(int);
	void Write(ofstream&);
protected:
	enum{max = 100};
	complex<double> V; // the node voltage 
	
	int id;  // this is intended to represent the node id 
	Polarity	nodePol;
	Element* eleArr[max];
	int lastElment;  // this the id of last element in relation to the node 
};
