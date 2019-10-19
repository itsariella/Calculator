#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T> *next;
};

template <class T>
class SLinkedList
{
public:
	Node<T>* head = nullptr;
	SLinkedList() {
		head = new Node<T>;
		head->next = nullptr;
	}

	T front() {
		return head->data;
	}

	void insertFront(const T elem) {
		Node<T> *nextPtr = new Node<T>;
		nextPtr->data = elem;
		nextPtr->next = head;
		head = nextPtr;
	}

	void insertRear(const T elem) {

		Node<T> *nodePtr = head;
		while (nodePtr->next != NULL)
		{
			nodePtr = nodePtr->next;
		}
		Node<T> *nextPtr = new Node;
		nodePtr->next = nextPtr;
		nextPtr->data = elem;
		nextPtr->next = nullptr;
	}

	void removeRear()
	{
		if (!head)
		{
			return;
		}
		if (head->next == NULL)
		{
			delete head;
			return;
		}

		//Find second to last node
		Node<T> *second_last = head;
		while (second_last->next->next != NULL)
		{
			second_last = second_last->next;
		}
		delete second_last->next;
		second_last->next = NULL;
	}


	void removeFront()
	{
		if (head == NULL)
		{
			return;
		}

		Node<T>* temp = head;
		head = head->next;
		delete temp;

	}
};
