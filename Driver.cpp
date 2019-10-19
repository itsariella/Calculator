/*  Program: Project 2
	Author: Ariella Navarro
	Class: CSCI 220
	Date: 10/10/2019
	Description: Calculator and Stack Implementation

	I certify that the code below is my own work.

	Exception(s): N/A

*/
#include "Calculator.h"
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string expression;

	cout << "Calculator by Ariella Navarro" << endl;
	cout << "Enter 0 to exit the program" << endl << endl;
	cout << "Enter an expression: ";
	getline(cin, expression);

	while (expression != "0")
	{
		Calculator myCalc(expression);
		cout << endl << "Enter an expression: ";
		getline(cin, expression);
	}
	cout << "Thanks for using my calculator." << endl;


	return 0;
}