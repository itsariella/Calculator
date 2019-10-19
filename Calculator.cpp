
#include "Calculator.h"
#include <sstream>

//receives a valid expressiona
Calculator::Calculator(string expression) {
	bool valid = balancingSymbols(expression);
	if (valid)
	{
		setExpr(expression);
		cout << "Postfix: " << postfix() << endl;
		cout << "Result: " << eval() << endl;
	}
	else
	{
		cout << "Invalid Expression!" << endl;
	}

}

//checks for precedence 
int Calculator::precedence(string op)
{
	if (op == "(")
	{
		return 4;
	}
	else if (op == "^")
	{
		return 3;
	}
	else if (op == "*" || op == "/" || op == "%")
	{
		return 2;
	}
	else if(op == "+" || op == "-")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//returns the postfix expression, arranges stack of symbols according to precedence then stores into postfix
string Calculator::postfix() { 

	istringstream toInt(infix);
	string holder;
	Stack <string> symbols;

	int num = 0;

	while (getline(toInt, holder, ' '))
	{

		//if operand then add to the string
		if (istringstream(holder) >> num) 
		{
			post += holder + " ";

		}
		//if operator
		if ((holder == "+" || holder == "-" || holder == "*" || holder == "/" || holder == "%" || holder == "^" || holder == "(") || holder == ")")
		{

			if (holder == "(")
			{
				symbols.push(holder);

			}
			else if(holder == ")")
			{
				//while the stack is not empty and opening pair not found
				while (!symbols.empty() && symbols.top() != "(")
				{
					//add item to the string
					string temp = symbols.pop();
					post += temp + " ";
				}
				// remove opening parenthesees
				symbols.pop(); 

			}
			else
			{
				//if operator is found and the stack is not empty
				if (!symbols.empty() && symbols.top() == "(")
				{
					symbols.push(holder);

				}
				else {
					//while operator is found and it has less precedence
					while (!symbols.empty() && precedence(holder) < precedence(symbols.top()))
					{
						string temp = symbols.pop();
						post += temp + " ";
					}
					symbols.push(holder);
				}
			}

		}
	}

	//add remaining elements of stack to postfix string
	while (!symbols.empty())
	{
		post += symbols.pop() + " ";
	}


	return post;
} 

//returns the result of the expression
int Calculator::eval() { 

	Stack <string> symbols;
	istringstream toInt(post);
	string holder;
	string op;
	int num = 0;
	int count = 0;
	int first = 0;
	int second = 0;
	int result = 0;

	//iterate through string and store into stack 
	if (post == "N/A ")
	{
		return 0;
	}
	while (getline(toInt, holder, ' '))
	{
		if (istringstream(holder) >> num)
		{
			myStack.push(num);
			count++;
		}
		if (holder == "+" || holder == "-" || holder == "*" || holder == "/" || holder == "%" || holder == "^")
		{
			symbols.push(holder);
		}


		//if there are two elements in the stack and an operator has been input, replace the two elem with result
		if (count >= 2 && !symbols.empty())
		{
			
			first = myStack.pop();
			second = myStack.pop();
			op = symbols.pop();

			if (op == "+")
			{
				myStack.push(first + second);

			}
			else if (op == "-")
			{
				myStack.push(second - first);
			}
			else if (op == "*")
			{
				myStack.push(first * second);
			}
			else if (op == "/")
			{
				myStack.push(second / first);
			}
			else if(op == "%")
			{
				myStack.push(second % first);
			}
			else if (op == "^")
			{
				myStack.push(power(second,first));

			}
			count--;
		}
	}

	result = myStack.pop();
	return result;

}

//receives the infix expression as a string and stores it
void Calculator::setExpr(string e) { 
	infix = e;
}

//returns the infix expression as string
string Calculator::getexpr() {  
	return infix;
}

//function used for exponentials, called when ^ is found in expression
int Calculator::power(int a, int b) { 
	if (b == 0)
	{
		return 1;
	}
	else {
		return a * power(a, b - 1);
	}
}


bool Calculator::balancingSymbols(string x)
{
	Stack <char> symbols;

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == '(' || x[i] == '{' || x[i] == '[')
		{
			symbols.push(x[i]);
		}
		if (x[i] == ')' || x[i] == '}' || x[i] == ']')
		{
			if (symbols.empty()) //missing opening brackets
			{
				if (x[i] == ')')
				{
					cout << "Missing '(' bracket. " << endl;
				}
				if (x[i] == '}')
				{
					cout << "Missing '{' bracket. " << endl;
				}
				if (x[i] == ']')
				{
					cout << "Missing '[' bracket. " << endl;
				}

				return false;
			}
			if (symbols.top() == '(' && symbols.top() != x[i] - 1) // checks if the closing bracket matches type of the top of the stack
			{
				cout << "Expected ) instead of '" << x[i] << "'" << endl;
				return false;
			}
			if ((symbols.top() == '[' || symbols.top() == '{') && symbols.top() != x[i] - 2)
			{
				if (symbols.top() == '[')
				{
					cout << "Expected ']' instead of '" << x[i] << "'" << endl;
				}
				else
				{
					cout << "Expected '}' instead of '" << x[i] << "'" << endl;
				}
				return false;
			}
			symbols.pop();
		}

	}

	if (symbols.empty())
	{
		return true;
	}
	else
	{
		if (symbols.top() == '(')
		{
			cout << "Missing ) " << endl;
		}
		while (!symbols.empty())
		{
			symbols.pop(); //empty the stack for reuse
		}
		return false;
	}

}