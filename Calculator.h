#pragma once
#include <string>
#include "Stack.h"

using namespace std;

class Calculator
{
public:
	Calculator(string expression = ""); //receives a valid expression
	string postfix(); //returns the postfix expression
	string getexpr(); //returns the infix expression as string
	void setExpr(string e); //receives the infix expression as a string and stores it
	int precedence(string op); //higher precedence returns higher value
	int eval(); //returns the result of the expression
	int power(int a, int b); 
	bool balancingSymbols(string x);
private:
	string infix;
	string post;
	int result;
	Stack <int> myStack;
};