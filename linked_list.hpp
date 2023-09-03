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

    if (p->next == NULL) {//设置递归条件，到达尾部节点
        head = p;//p的下一个节点是NULL，说明head已经是原节点的尾部元素了
        return;
    }
    recurse(p->next);

    //到达尾部，开始执行归
    //每次递归改变节点指向，使得后面的节点指向反转成指向前面的节点，并先把前面的节点的前面的节点置为空，在下一个递归又会接着循环下去
    //执行到哪一个的时候，这个调用结束的节点以及之前调用的所有节点都已经反转
    Node* q = p->next;
    q->next = p;
    p->next = nullptr;
}

void LinkedList::recurse(Node* p, int val) {//重载版本从头节点到值为val的结点进行一次反转(旋转链表)
    
    if (p->next->data == val) {
        head = p;
        return;
    }
    recurse(p->next);

    Node* q = p->next;
    q->next = p;
    p->next = nullptr;
}
