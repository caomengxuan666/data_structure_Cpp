#pragma once
#include"linked_list.hpp"
class DoubleNode : public Node {
public:
    DoubleNode(ElementType data, DoubleNode* n = nullptr, DoubleNode* m = nullptr) : Node(data), next(n), prev(m) {}

    DoubleNode* prev;
    DoubleNode* next;
};

class DoubleLinked_List :public LinkedList {
public:

    DoubleLinked_List() : head(nullptr) {}
    void searchAll();
    void rSearchAll(DoubleNode* p);
    void newNode(int val);
    void headInsertNode(int val);
    void posInsert(int val);
    void reverse();
    void posInsert(int val, int n);
    void delNode(int n);

    DoubleNode* head;
};
void DoubleLinked_List::searchAll() {
    DoubleNode* p = head;
    while (p != nullptr) {
        cout << "The value is: " << p->data << endl;
        p = p->next;
    }
}

void DoubleLinked_List::rSearchAll(DoubleNode* p) {
    if (p == nullptr) {
        return;
    }
    cout << "The value is: " << p->data << endl;
    rSearchAll(p->next);
}
void DoubleLinked_List::newNode(int val) {
    DoubleNode* newNode = new DoubleNode(val);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        DoubleNode* p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = newNode;
        newNode->prev = p;
    }
}

void DoubleLinked_List::headInsertNode(int val) {
    DoubleNode* newNode = new DoubleNode(val);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoubleLinked_List::posInsert(int val, int n) {
    DoubleNode* newNode = new DoubleNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    if (n <= 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        DoubleNode* p = head;
        int count = 1;
        while (p->next != nullptr && count < n - 1) {
            p = p->next;
            count++;
        }
        newNode->next = p->next;
        if (p->next != nullptr) {
            p->next->prev = newNode;
        }
        p->next = newNode;
        newNode->prev = p;
    }
}

void DoubleLinked_List::delNode(int n) {
    if (head == nullptr) {
        return;
    }
    if (n <= 1) {
        DoubleNode* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }
    else {
        DoubleNode* p = head;
        int count = 1;
        while (p != nullptr && count < n) {
            p = p->next;
            count++;
        }
        if (p != nullptr) {
            p->prev->next = p->next;
            if (p->next != nullptr) {
                p->next->prev = p->prev;
            }
            delete p;
        }
    }
}

void DoubleLinked_List::reverse() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    DoubleNode* p = head;
    DoubleNode* temp = nullptr;
    while (p != nullptr) {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev;
    }
    if (temp != nullptr) {
        head = temp->prev;
    }
}
