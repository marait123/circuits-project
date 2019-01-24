#include"includes.h"
#include"Solver.h"

Solver::Solver()
{
	nTop = 0;
	Omega = 60;
	eTop = 0;

	for (size_t i = 0; i < MaxNum; i++)
	{ 
		N[i] = NULL;
		EE[i] = NULL;
/*
		PE[i] = NULL;
		AE[i] = NULL;
		 */
	}
}

Solver::~Solver()
{

}

void Solver::Read() {

	string fileName;

	cout << "please enter the file name (on the form (filename.txt)) : ";
	
	cin >> fileName;

		ifstream file;
		file.open(fileName.c_str());

		if (file.fail()) {
			cout << "file doesn't exist /n`click anywhere to exit\n";
			cin.get();
			cin.ignore();
			exit(1);
			return;

		}
		while (!file.eof())
		{

			// every line represents a new element added to the list so
			// at the end of the while loop i have incremented the count so no need to increment it 
			// but the count of nodes you have to increment every  time you create a new node 
			
			string line;

			getline(file, line);

			istringstream sLine(line);
		
			/*
Vs 1 0 10 30
L1 1 2 .001
C2 2 3 0.0001
R3 3 0 10
kind firstNode second Node value
*/
			

			string word;
			sLine >> word;
			ToUpper(word);  // this ensures that capitalization doesn't matter
			complex <double> eVal; // the element value

			if ( word == "VS") {  // first node means negative 
				string Data[MaxData];

				sLine >> word;
				int id1 = atoi(word);

				sLine >> word;
				int id2 = atoi(word);

				sLine >> word;
				double mag = atof(word);			// value(volt) magnitude
				
				sLine >> word;
				double ang = atof(word);			// value(volt) agnle

				double zZ = mag * cos(ang* pi/180);
				double rR = mag * sin(ang* pi / 180);
				complex<double> vVal(zZ, rR);

				// first construct the tow nodes and add the element to them and if they exist you add element to nodes only


				EE[eTop] = new VSI();
				EE[eTop]->SetVolt(vVal);


				nMit = nodeMap.find(id1);
				if (nMit == nodeMap.end()) { // if i didn't find the id recorded
					N[id1] = new Node(id1);
					N[id1]->AddElemnt(EE[eTop]);
					nodeMap.insert(pair<int, Node*>(id1, N[id1]));
					nTop++;
				}

				else

				{

					N[id1]->AddElemnt(EE[eTop]);

				}

				nMit = nodeMap.find(id2);
				if (nMit == nodeMap.end()) { // if i didn't find the id recorded then construct and add to the map
					
					N[id2] = new Node(id2);
					N[id2]->AddElemnt(EE[eTop]);
					nodeMap.insert(pair<int, Node*>(id2, N[id2]));
					nTop++;

				}

				else

				{

					N[id2]->AddElemnt(EE[eTop]);

				}




				EE[eTop]->SetNode1(N[id1]);
				EE[eTop]->SetNode2(N[id2]);

				
				N[id1]->SetPol(Polarity::Neg);
				N[id2]->SetPol(Polarity::Pos);



			}

			if (word == "IS") {
				// not yet
				
			}

			else if (word.substr(0,1) == "L")
			{ 

				string Data[MaxData];
				sLine >> word;
				int id1 = atoi(word);

				sLine >> word;
				int id2 = atoi(word);

				sLine >> word;
				double lMag = atof(word);			// value(INDUCTANCE) magnitude
				 



				// first construct the tow nodes and add the element to them and if they exist you add element to nodes only


				EE[eTop] = new L(lMag);


				nMit = nodeMap.find(id1);
				if (nMit == nodeMap.end()) { // if i didn't find the id recorded
					N[id1] = new Node(id1);
					N[id1]->AddElemnt(EE[eTop]);
					nTop++;
					nodeMap.insert(pair<int, Node*>(id1, N[id1]));
				}

				else

				{

					N[id1]->AddElemnt(EE[eTop]);

				}

				nMit = nodeMap.find(id2);
				if (nMit == nodeMap.end()) { // if i didn't find the id recorded

					N[id2] = new Node(id2);
					N[id2]->AddElemnt(EE[eTop]);
					nTop++;
					nodeMap.insert(pair<int, Node*>(id2, N[id2]));
				}

				else

				{
					N[id2]->AddElemnt(EE[eTop]);
				}

				EE[eTop]->SetNode1(N[id1]);
				EE[eTop]->SetNode2(N[id2]);

				N[id1]->SetPol(Polarity::Neg);
				N[id2]->SetPol(Polarity::Pos);

			}

			else if (word.substr(0,1) == "C")
			{

				string Data[MaxData];

				sLine >> word;
				int id1 = atoi(word);

				sLine >> word;
				int id2 = atoi(word);

				sLine >> word;
				double cMag = atof(word);			// value(CAPACITANCE) magnitude
													// first construct the tow nodes and add the element to them and if they exist you add element to nodes only

				EE[eTop] = new C(cMag);
				
				nMit = nodeMap.find(id1);
				if (nMit == nodeMap.end()) { // if i didn't find the id recorded
					N[id1] = new Node(id1);
					N[id1]->AddElemnt(EE[eTop]);
					nTop++;
					nodeMap.insert(pair<int, Node*>(id1, N[id1]));
				}

				else

				{

					N[id1]->AddElemnt(EE[eTop]);

				}

				nMit = nodeMap.find(id2);

				if (nMit == nodeMap.end())
				{ // if i didn't find the id recorded

					N[id2] = new Node(id2);
					N[id2]->AddElemnt(EE[eTop]);
					nTop++;
					nodeMap.insert(pair<int, Node*>(id2, N[id2]));
				}

				else
				{
					N[id2]->AddElemnt(EE[eTop]);
				}

				EE[eTop]->SetNode1(N[id1]);
				EE[eTop]->SetNode2(N[id2]);

				N[id1]->SetPol(Polarity::Neg);
				N[id2]->SetPol(Polarity::Pos);
				}

			else if (word.substr(0,1) == "R")
			{

				string Data[MaxData];

				sLine >> word;
				int id1 = atoi(word);

				sLine >> word;
				int id2 = atoi(word);

				sLine >> word;
				double rMag = atof(word);			// value(CAPACITANCE) magnitude
										
				// first construct the tow nodes and add the element to them and if they exist you add element to nodes only
				EE[eTop] = new R(rMag);


				nMit = nodeMap.find(id1);
				if (nMit == nodeMap.end()) { // if i didn't find the id recorded
					N[id1] = new Node(id1);
					N[id1]->AddElemnt(EE[eTop]);
					nTop++;
					nodeMap.insert(pair<int, Node*>(id1, N[id1]));
				}

				else

				{

					N[id1]->AddElemnt(EE[eTop]);

				}

				nMit = nodeMap.find(id2);

				if (nMit == nodeMap.end())
				{ // if i didn't find the id recorded

					N[id2] = new Node(id2);
					N[id2]->AddElemnt(EE[eTop]);
					nTop++;
					nodeMap.insert(pair<int, Node*>(id2, N[id2]));
				}

				else
				{
					N[id2]->AddElemnt(EE[eTop]);
				}

				EE[eTop]->SetNode1(N[id1]);
				EE[eTop]->SetNode2(N[id2]);

				N[id1]->SetPol(Polarity::Neg);
				N[id2]->SetPol(Polarity::Pos);
			}

			else
			{
			 
			}
			eTop++;  // after reading eache element on every single line increase the element count by one 
		}

		file.close(); //don't forget to close the file 

}
void Solver::Solve(){
	if (N[0] == NULL) {
		cout << "there is a problem no 0 node exist " << endl;
		return;
	}

	N[0]->SetVolt(0);  // reference node


	// finding the loop current since it solves one node then find the current
	// MatrixXd m; no need 
	complex<double> vTot;
	complex<double> zTot;
	complex<double> iTot;

	for (size_t i = 0; i < eTop; i++)
	{
		if(dynamic_cast<VSI*>(EE[i])){
			vTot += EE[i]->GetVolt();
		}
		else if (dynamic_cast<PassiveElement*>(EE[i]))
		{
			zTot += EE[i]->GetImpedence();
		}
		else throw "couldn't identify the element type in solve function. ";
	}

	iTot = vTot / zTot;

	for (size_t i = 0; i < eTop; i++)
	{
		if (dynamic_cast<PassiveElement*>(EE[i]))
		{
			EE[i]->SetVolt(iTot * EE[i]->GetImpedence());
		}
		EE[i]->SetCurr(iTot);
	}

	for (size_t i = 1; i < nTop; i++)
	{
		if (N[0]->GetId() == N[i]->GetId())
		{
			break;  // this means the end of the loop 
		}

		complex<double> volt;

		if (dynamic_cast<VSI*>(EE[i - 1])) {
			volt = N[i - 1]->GetVolt() + EE[i - 1]->GetVolt();

		}
		else if (dynamic_cast<PassiveElement*>(EE[i - 1])) {
			volt = N[i - 1]->GetVolt() - EE[i - 1]->GetVolt();
		}

		N[i]->SetVolt(volt);
		 
	}

}



void Solver::Write() {

	ofstream oFile("out.txt");

	if (oFile.fail()) {
		throw "sorry there is n't enough space to make a file on the disk";
		return;
	}

	
	for (size_t i = 0; i < nTop; i++)
	{
		N[i]->Write(oFile);
		oFile << endl;
	}

	
	for (size_t i = 0; i < eTop; i++)
	{
		EE[i]->Write(oFile);
		oFile << endl;
	}
	
	


	oFile.close();


}
