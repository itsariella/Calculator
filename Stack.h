#pragma once
#include <string>
#include "SLinkedList.h"


using namespace std;
template <typename E>

class Stack {

public:
	Stack<E>()
		: S(), n(0) {};

	int size() const
	{
		return n;
	}

	bool empty() const
	{
		return n == 0;
	}

	E top() {
		if (empty())
		{
			throw runtime_error("Top of empty stack");

		}
		else
		{
			return S.front();
		}
	}

	void push(const E &e)
	{
		++n;
		S.insertFront(e);
	}

	E pop()
	{

		if (empty())
		{
			throw runtime_error("Empty stack");
		}
		else
		{
			E front = S.front();
			--n;
			S.removeFront();
			return front;
		}

	}

private:
	int n;
	SLinkedList <E> S;
};