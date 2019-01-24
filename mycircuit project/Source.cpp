#include"includes.h"
#include"elements/Element.h"
#include"elements/Capacitor.h"

#include"Solver.h"
#define JC complex<double> (0,1)

typedef complex<double> CD;

void getMat(MatrixXcd& matC, int row ,int col){

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			double real, imag;
			cout << "enter the (" << i << "," << j << ") : ";
			cin >> real >> imag;
			matC(i, j) = CD(real, imag);
		}
	}
}

int main() {

	
	//the comment includes how to use the matrix and complex 
	/*
	complex<double > c;
	c.real(7);
	c.imag(3);
	cout << c <<endl << arg(c) <<endl;
	Matrix<complex<double>, 2, 2> mat1;
	mat1 << complex<double>(6, -3), complex<double>(0, 3),
		complex<double>(0, 3), complex<double>(5, 1);
	cout << mat1 << endl;
	Matrix<complex<double>, 2, 1> mat2;
	cout << "*" << endl;
	mat2 << complex<double>(0, 3), complex<double>(0, 3);
	cout << mat2 << endl;
	cout << " = " << endl << mat1.inverse()* mat2 << endl;
	cin.get();
	cin.ignore();
	*/
	//how to use the substr below
	/*
	string word = "Ali";
	if (word.substr(0,2) == "Al") {
		cout << "yes " << word.substr(0,2) << endl;
	}
	else
	{
		cout << "no" << endl;

	}*/
	/*
	//the solution of the q in the dr slides 

	Matrix<complex<double>, 2, 2> eqCoef;

	eqCoef << complex<double>(8, 8), complex<double>(0, 2)
		, complex<double>(0, 2), complex<double>(4, -4);


	Matrix<complex<double>, 2, 1> eqRes;

	eqRes << complex<double>(0, 50), complex<double>(0, -30);


	cout << " = " << eqCoef.inverse() * eqRes << endl;

	*/

    /*
	complex<double> c(0,1);  //complex double can only be nultiplyied by double no int or even float

	complex<double> R(0, 1);

	R =  c * 608.2;
	double temp = 1;
	R = complex<double>(1,0) / (c * double(60) * double(.2));

	cout << "1/jwc = " << R;
	*/

	/*
	Element* p = new C(.2);
	cout << p->GetImpedence();

	MatrixXcd matV, matC;

	cout << endl;
	cout << "enter the number of the matrix dimenstion : ";
	int dim;
	cin >> dim;

	matC.resize(dim, dim);
	matV.resize(dim, 1);

	getMat(matC, dim, dim);
	getMat(matV, dim, 1);

	cout << "ans matC^=1 * matV = \n" << matC.inverse() * matV <<endl;
	

	cout << matC << endl;*/

	
	try
	{
		Solver s;
		s.Read();

		s.Solve();
		s.Write();
	}
	catch(string sExcep){
		cout << sExcep << endl;
	}
	catch (const std::exception& c)
	{
		cout << c.what() <<endl;
	}
	cout << "the output is in a file called out.txt next to the .exe if you have notepad installed then the output will show immediately thank you" << endl;
	system("start out.txt");

	cin.get();
	cin.ignore();
	return 0;
}