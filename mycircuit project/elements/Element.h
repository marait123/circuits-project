#pragma once

#include"../includes.h"
#include"Node.h"

class Node;


class Element
{


protected:
	complex<double> Z;  // Z stands for impedence

	complex<double> Volt;  // Z stands for Voltage 

	complex<double> Curr;  // Z stands for Current 

	
	Node* N[2];

public:

	Element();
	~Element();
	void SetNode1(Node*);
	Node* GetNode1();
	void SetNode2(Node*);
	Node* GetNode2();
	virtual void SetImpedence(complex<double>);
	virtual complex<double> GetImpedence();

	virtual void SetVolt(complex<double>);
	virtual complex<double> GetVolt();

	virtual void SetCurr(complex<double>);
	virtual complex<double> GetCurr();

	void Write(ofstream&);


};

