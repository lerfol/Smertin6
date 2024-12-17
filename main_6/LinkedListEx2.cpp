#include "LinkedListEx2.h"
#include <iostream>
using namespace std;

void LinkedListEx2::append(int data) {
	Node* newnode = new Node{ data, NULL, tail };
	if (!head) {
		head = newnode;
		tail = newnode;
	}
	else {
		tail->next = newnode;
		newnode->pr = tail;
		tail = newnode;
	}
}
void LinkedListEx2::del(Node* t) {
	if (head == t) {
		head->next->pr = NULL;
		head = head->next;
		return;
	}
	if (tail == t) {
		tail->pr->next = NULL;
		tail = tail->pr;
		return;
	}
	t->pr->next = t->next;
	t->next->pr = t->pr;
}

LinkedListEx2:: Node* LinkedListEx2::GetNext(Node* node) {
	return node->next ? node->next : NULL;
}
LinkedListEx2:: Node* LinkedListEx2::GetPr(Node* node) {
	return node->pr ? node->pr : NULL;
}

void LinkedListEx2:: LinkedListEx2::Print() {
	Node* curr = head;
	if (!head) {
		cout << "Списка не существует!" << endl;
	}
	else {
		cout << "Список содержит: " << endl;
		while (curr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
}