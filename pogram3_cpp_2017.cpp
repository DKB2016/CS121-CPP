#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdio.h> 


using namespace std;


void dostuff(char T, int F1, int F2, int F3, int F4, double &TTL, ofstream &outFile)
{

	double Ptotal, Ftotal, Ctotal, Mtotal, Ototal;
		switch(T)
	{
		case 'P':
			Ptotal = (((.89 * F1 * F2 * F3 * F4)) / 144.0);
			TTL += Ptotal;
			outFile << setprecision(3) << F1  << " " << F2 << "x" << F3 << "x" << F4 << " " << "Pine"<< ", Cost: " << Ptotal << endl;
			break;
		case 'F':
			Ftotal = (((1.09 * F1 * F2 * F3 * F4))/144.0);
			TTL += Ftotal;
			outFile << setprecision(3) << F1 << " " << F2 << "x" << F3 << "x" << F4 << " " << "Fir" << ", Cost: " << Ftotal << endl;
			break;
		case 'C':
			Ctotal = (((2.26 * F1 * F2 * F3 * F4))/144.0);
			TTL += Ctotal;
			outFile << setprecision(3) << F1 << " " << F2 << "x" << F3 << "x" << F4 << " " << "Cedar" << ", Cost: " << Ctotal << endl;
			break;
		case 'M':
			Mtotal = (((4.50 * F1 * F2 * F3 * F4))/144.0);
			TTL += Mtotal;
			outFile << setprecision(3) << F1 << " " << F2 << "x" << F3 << "x" << F4 << " " << "Maple" << ", Cost: " << Mtotal << endl;
			break;
		case 'O':
			Ototal = (((3.10 * F1 * F2 * F3 * F4))/144.0);
			TTL += Ototal;
			outFile << setprecision(3) << F1 << " " << F2 << "x" << F3 << "x" << F4 << " " << "Oak" << ", Cost: " << Ototal << endl;
			break;
		case 'T':
			outFile << "Total: " << TTL;
			break;

		}

	}




int main()
{
	double Total;
	ifstream SS;
	ofstream outFile("test.txt");


	
	char type;
	int f1, f2, f3, f4;
	SS.open("file.txt");

	while (SS)
		{
			SS >> type >> f1 >> f2 >> f3 >> f4;
			//cout << type << " " << f1 << " " << f2 << " " << f3 << " " << f4 << endl;


			dostuff(type, f1, f2, f3, f4, Total, outFile); 
	
		}
		return 0;
}
	


