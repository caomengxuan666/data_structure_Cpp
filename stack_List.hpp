#pragma once
#include<iostream>
using namespace std;
typedef size_t ElementaryType;

class stackNode {
public:
    stackNode(ElementaryType d, stackNode* n = nullptr) : data(d), next(n) {}
    ElementaryType data;
    stackNode* next;
};

class stack_List {

public:
    stack_List() : head(nullptr) {}

    void push(ElementaryType val) {
        stackNode* newNode = new stackNode(val);
        if (head==nullptr) {
            head = newNode;
        }
        else {
            newNode->next = head;//这里简化了代码，本来是用temp存储head->next然后让temp指向newNode的
            head = newNode;//简化过后是将新节点的next指向原来头结点指向的节点，然后直接将该新节点设置成头结点
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Failed to operate 'pop': Error: Empty stack" << endl;
            return;
        }
        stackNode* temp = head;
        head = head->next;
        delete temp;
    }

    void top() {
        if (isEmpty()) {
            cout << "Failed to operate 'top': Error: Empty stack" << endl;
            return;
        }
        cout << "The top element is: " << head->data << endl;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    stackNode* gethead() {
        return head;
    }

private:

    stackNode* head;
};
