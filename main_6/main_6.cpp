#include <iostream>
#include <clocale>
#include<list>
#include <ctime>
#include "ListEx1.h"
#include "LinkedListEx2.h"
using namespace std;

void Ex1(ListEx1 l1, ListEx1 l2) {
    ListEx1 l3;
    auto* temp = l1.head;
    auto* temp2 = l2.head;
    int k = 0;
    while (temp) {
        k = 0;
        temp2 = l2.head;
        while (temp2) {
            if (temp->data != temp2->data) {
                temp2 = temp2->next;
            }
            else {
                k++;
                break;
            }
        }
        if (k == 0) {
            l3.append(temp->data);
        }
        temp = temp->next;
    }
    temp = l1.head;
    temp2 = l2.head;
    while (temp2) {
        k = 0;
        temp = l1.head;
        while (temp) {
            if (temp2->data != temp->data) {
                temp = temp->next;
            }
            else {
                k++;
                break; 
            }
        }
        if (k == 0) {
            l3.append(temp2->data);
        }
        temp2 = temp2->next;
    }
    l3.CoutList();
}

void Ex2(LinkedListEx2 l) {
    l.Print();
    auto* curr = l.head;
    int minel, maxel;
    minel = curr->data;
    maxel = curr->data;
    while (curr) {
        minel = min(minel, curr->data);
        maxel = max(maxel, curr->data);
        curr = curr->next;
    }
    cout << minel << " " << maxel << endl;
    curr = l.head;
    int k = 0;
    while (curr->data != maxel && curr->data != minel) {
        curr = curr->next;
    }
    if (curr->data==minel){
        curr = curr->next;
        while (curr->data != maxel) {
            auto* temp = curr->next;
            l.del(curr);
            curr = temp;
        }
    }
    else {
        curr = curr->next;
        while (curr->data != minel) {
            auto* temp = curr->next;
            l.del(curr);
            curr = temp;
        }
    }
    l.Print();
}


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    //#1
    cout << "#1" << endl;
    ListEx1 l1;
    for (int i = 0; i < 5; i++) {
        l1.append(i);
    }
    ListEx1 l2;
    for (int i = 3; i < 10; i++) {
        l2.append(i);
    }
    l1.CoutList();
    l2.CoutList();
    Ex1(l1, l2);
    //#2
    cout << "#2" << endl;
    LinkedListEx2 l;
    for (int i = 0; i < 10; i++) {
        l.append(rand()%100);
    }
    Ex2(l);

}

