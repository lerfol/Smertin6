#pragma once
#include <iostream>
using namespace std;

class LinkedListEx2
{
public:
	struct Node {
		int data;
		Node* next;
		Node* pr;
	};

	Node* head;
	Node* tail;
	LinkedListEx2() : head(nullptr), tail(nullptr) {}

	void append(int data);
	void del(Node* t);

	Node* GetNext(Node* node);
	Node* GetPr(Node* node);

	void Print();
};

