#include "ListEx1.h"


void ListEx1::append(int d) {
	Node* newnode = new Node(d);
	if (!head) {
		head = newnode;
	}
	else {
		Node* curr = head;
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = newnode;
	}
}

void ListEx1::del(int d) {
	if (!head || head->data == d) {
		head = head ? head->next : NULL;
		cout << "������� ������!" << endl;
		return;
	}
	Node* curr = head;
	while (curr->next && curr->next->data != d) {
		curr = curr->next;
	}
	if (curr->next && curr->next->data == d) {
		curr->next = curr->next->next;
		cout << "������� ������!" << endl;
	}
	else {
		cout << "�������� ���!" << endl;
	}
}

void ListEx1:: CoutList() {
	Node* curr = head;
	cout << "������ �����: " << endl;
	if (curr) {
		while (curr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
	else {
		cout << "������ �� ����������!" << endl;
	}

}