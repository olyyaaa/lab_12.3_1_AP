// lab_AP_12.03_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class List {
public:
    Node* head;
    Node* tail;
public:
    List() {
        head = NULL;
        tail = NULL;
    }

    void addToEnd(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;
        temp->prev = tail;
        if (tail != NULL) {
            tail->next = temp;
        }
        tail = temp;
        if (head == NULL) {
            head = temp;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }
};

void deleteElementsBeforeValue(List& list, int value) {
    Node* current = list.getHead();
    while (current != NULL && current->data != value) {
        Node* toDelete = current->prev;
        if (toDelete != NULL) {
            if (toDelete->prev != NULL) {
                toDelete->prev->next = current;
            }
            else {
                list.head = current;
            }
            current->prev = toDelete->prev;
            delete toDelete;
        }
        current = current->next;
    }
}

int main() {
    List list;
    list.addToEnd(1);
    list.addToEnd(2);
    list.addToEnd(3);
    list.addToEnd(4);
    list.addToEnd(5);

    cout << "List before deletion: ";
    list.printList();

    int valueToDelete = 4;
    deleteElementsBeforeValue(list, valueToDelete);

    cout << "List after deletion: ";
    list.printList();

    return 0;
}