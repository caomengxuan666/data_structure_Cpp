#pragma once

#include "Double_Linked.hpp"


class Circle_Double_Linked_List : public DoubleLinked_List {
public:
    Circle_Double_Linked_List(int firstVal) : head(nullptr) {
        DoubleNode* firstNode = new DoubleNode(firstVal);
        head = firstNode;
        head->next = head;
        head->prev = head;
    }
    void searchAll();
    void headInsertNode(int val);
    DoubleNode* head;
};

void Circle_Double_Linked_List::searchAll() {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    DoubleNode* current = head;

    cout << "The values are: ";
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

void Circle_Double_Linked_List::headInsertNode(int val) {
    DoubleNode* newNode = new DoubleNode(val);
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
    }
    else {
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
}
