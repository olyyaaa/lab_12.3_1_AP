// lab_AP_12.03_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

using namespace std;

// Структура для представлення елемента списку
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

// Функція для додавання елемента до списку
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

// Функція для видалення елемента зі списку
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

// Функція для виведення списку на екран
void printList(Node* head) 
{
    while (head != NULL) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Функція для видалення елементів перед елементом зі значенням value
void deleteBeforeValue(Node** headRef, int value) 
{
    if (*headRef == nullptr || (*headRef)->next == nullptr) 
    {
        // якщо списку не існує або він містить менше двох елементів
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
        // якщо елемент не знайдено або він є першим у списку
        return;
    }

    prevPrev->next = current;
    delete prev;
}



int main()
{
    Node* head = NULL;

    // Створення списку
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);

    // Виведення списку
    cout << "List before deleting:" << endl;
    printList(head);
    deleteBeforeValue(&head, 6);

    // Виведення списку після видалення елементів
    cout << "List after deleting:" << endl;
    printList(head);

    return 0;
}