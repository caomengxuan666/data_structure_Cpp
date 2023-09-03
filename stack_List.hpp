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
            newNode->next = head;//������˴��룬��������temp�洢head->nextȻ����tempָ��newNode��
            head = newNode;//�򻯹����ǽ��½ڵ��nextָ��ԭ��ͷ���ָ��Ľڵ㣬Ȼ��ֱ�ӽ����½ڵ����ó�ͷ���
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
