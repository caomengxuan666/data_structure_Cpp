#pragma once
#include <iostream>
#include <cstddef>
using namespace std;

typedef size_t ElementType;
class Node {
public:
    ElementType data;
    Node* next;

    Node(ElementType d, Node* n = nullptr) : data(d), next(n) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    void newNode(int val);
    void headInsertNode(int val);
    void posInsert(int val, int n);
    void delNode(int n);
    void reverse();
    void searchAll();
    void rSearchAll( Node* p);
    void recurse(Node* p);
    void recurse(Node* p, int val);
    Node* head;
};

void LinkedList::newNode(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::headInsertNode(int val) {
    head = new Node(val, head);
}

void LinkedList::posInsert(int val, int n) {
    if (n == 1) {
        headInsertNode(val);
        return;
    }

    Node* temp = head;
    Node* newNode = new Node(val);
    int nums = 1;
    while (temp != nullptr) {
        if (nums == n - 1) {
            Node* tmp = temp->next;
            temp->next = newNode;
            newNode->next = tmp;
            break;
        }
        nums++;
        temp = temp->next;
    }
}

void LinkedList::delNode(int n) {
    Node* temp = head;
    if (n == 1) {
        head = temp->next;
        delete temp;
        return;
    }
    int nums = 1;
    while (temp != nullptr) {
        if (nums == n - 1) {
            Node* tmp = temp->next;
            temp->next = temp->next->next;
            delete tmp;
            break;
        }
        nums++;
        temp = temp->next;
    }
}

void LinkedList::reverse() {
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void LinkedList::searchAll() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "The value is: " << temp->data << endl;
        temp = temp->next;
    }
}

void LinkedList::rSearchAll(Node* p) {
    if (p == nullptr) {
        return;
    }
    cout << "The value is: " << p->data << endl;
    rSearchAll(p->next);
}

void LinkedList::recurse(Node* p) {

    if (p->next == NULL) {//���õݹ�����������β���ڵ�
        head = p;//p����һ���ڵ���NULL��˵��head�Ѿ���ԭ�ڵ��β��Ԫ����
        return;
    }
    recurse(p->next);

    //����β������ʼִ�й�
    //ÿ�εݹ�ı�ڵ�ָ��ʹ�ú���Ľڵ�ָ��ת��ָ��ǰ��Ľڵ㣬���Ȱ�ǰ��Ľڵ��ǰ��Ľڵ���Ϊ�գ�����һ���ݹ��ֻ����ѭ����ȥ
    //ִ�е���һ����ʱ��������ý����Ľڵ��Լ�֮ǰ���õ����нڵ㶼�Ѿ���ת
    Node* q = p->next;
    q->next = p;
    p->next = nullptr;
}

void LinkedList::recurse(Node* p, int val) {//���ذ汾��ͷ�ڵ㵽ֵΪval�Ľ�����һ�η�ת(��ת����)
    
    if (p->next->data == val) {
        head = p;
        return;
    }
    recurse(p->next);

    Node* q = p->next;
    q->next = p;
    p->next = nullptr;
}
