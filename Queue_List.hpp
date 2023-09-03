#pragma once
#include <iostream>

typedef size_t ElementaryType;

class QueueNode {
public:
    QueueNode(ElementaryType d) : data(d), next(nullptr), front(nullptr) {}
    ElementaryType data;
    QueueNode* next;
    QueueNode* front;
};

class Queue_List {
public:
    Queue_List() : head(nullptr), rear(nullptr) {}

    void Enqueue(ElementaryType val) {
        QueueNode* temp = new QueueNode(val);
        if (head == nullptr && rear == nullptr) {
            head = rear = temp;
            return;
        }
        rear->next = temp;
        temp->front = rear;
        rear = temp;
    }

    void Dequeue() {
        if (head == nullptr) {
            return;
        }
        QueueNode* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->front = nullptr;
        }
        delete temp;
    }

    void PrintFront() {
        if (head == nullptr)
            return;
        std::cout << "The front element is: " << head->data << std::endl;
    }

    void PrintEnd() {
        if (rear == nullptr)
            return;
        std::cout << "The end element is: " << rear->data << std::endl;
    }
private:
    QueueNode* head;
    QueueNode* rear;
};
