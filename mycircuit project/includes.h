#pragma once
#include<iostream>
#include<Eigen>
#include<complex.h>
#include<fstream>
#include<cmath>
#include<sstream>
#include<string>
#include"strutils.h"
#include<map>
#include<process.h>

enum Polarity {Pos,Neg};
const int OMEGA = 60;
const double pi = 3.141592654;

using namespace std;
using namespace Eigen;


//
//#include"elements/Node.h"
//#include "elements/Element.h"
//#include"elements/Node.h"
//#include"elements/PassiveElement.h"
//#include"elements/ActiveElement.h"
//#include"elements/Capacitor.h"
//#include"elements/Inductor.h"
//#include"elements/Resistor.h"
//
//#include"Solver.h"
