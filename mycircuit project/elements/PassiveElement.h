#pragma once
#include"../includes.h"

#include"Element.h"

class PassiveElement : public Element
{

public:
	PassiveElement();
	PassiveElement(complex<double>);
	~PassiveElement();
	virtual void SetImpedence(complex<double>);
	virtual complex<double> GetImpedence();

private:

};
