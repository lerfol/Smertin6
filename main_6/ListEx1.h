#pragma once
#include <cstddef>
#include <iostream>
using namespace std;

class ListEx1
{
public:
	struct Node {
		int data;
		Node* next;
		Node(int d): data(d), next(NULL){}
	};
	Node* head;

	ListEx1() : head(nullptr) {}

	void append(int d);
	void del(int d);
	void CoutList();
};

