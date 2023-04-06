// lab_AP_12.03_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

using namespace std;

// ��������� ��� ������������� �������� ������
struct Node 
{
    int data;
    Node* next;
    Node* prev;

    Node(int data) 
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

// ������� ��� ��������� �������� �� ������
void push(Node** head, int data) 
{
    Node* newNode = new Node(data);
    newNode->next = *head;
    if (*head != NULL) 
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// ������� ��� ��������� �������� � ������
void deleteNode(Node** head, Node* node) 
{
    if (*head == NULL || node == NULL) 
    {
        return;
    }
    if (*head == node)
    {
        *head = node->next;
    }
    if (node->next != NULL) 
    {
        node->next->prev = node->prev;
    }
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }
    delete node;
}

// ������� ��� ��������� ������ �� �����
void printList(Node* head) 
{
    while (head != NULL) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ������� ��� ��������� �������� ����� ��������� � ��������� value
void deleteBeforeValue(Node** headRef, int value) 
{
    if (*headRef == nullptr || (*headRef)->next == nullptr) 
    {
        // ���� ������ �� ���� ��� �� ������ ����� ���� ��������
        return;
    }

    Node* current = *headRef;
    Node* prev = nullptr;
    Node* prevPrev = nullptr;

    while (current != nullptr && current->data != value) 
    {
        prevPrev = prev;
        prev = current;
        current = current->next;
    }

    if (current == nullptr || prevPrev == nullptr) 
    {
        // ���� ������� �� �������� ��� �� � ������ � ������
        return;
    }

    prevPrev->next = current;
    delete prev;
}



int main()
{
    Node* head = NULL;

    // ��������� ������
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);

    // ��������� ������
    cout << "List before deleting:" << endl;
    printList(head);
    deleteBeforeValue(&head, 6);

    // ��������� ������ ���� ��������� ��������
    cout << "List after deleting:" << endl;
    printList(head);

    return 0;
}