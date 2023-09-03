#pragma once
#include <iostream>

template<class ElementaryType = size_t>
class Queue_Array {
public:
    Queue_Array(size_t size = 12) : index_size(size), index_Beg(-1), index_End(-1) {
        A = new ElementaryType[index_size];
    }

    ~Queue_Array() {
        delete[] A;
    }

    void Enqueue(ElementaryType val) {
        if (isFull()) {
            std::cout << "Failed to operate function 'Enqueue': Error: The queue is already full" << std::endl;
            return;
        }
        index_End = (index_End + 1) % index_size;
        A[index_End] = val;
    }

    void Dequeue() {
        if (isEmpty()) {
            std::cout << "Failed to operate function 'Dequeue': Error: The queue is already empty" << std::endl;
            return;
        }
        else if (index_Beg == index_End) {
            index_Beg = -1;
            index_End = -1;
            std::cout << "After this operation 'Dequeue', the queue is empty" << std::endl;
            return;
        }
        index_Beg = (index_Beg + 1) % index_size;
    }

    void front() {
        if (isEmpty()) {
            std::cout << "The queue is empty" << std::endl;
            return;
        }
        else if (index_Beg> index_size) {
            std::cout << "The front element is: " << A[0] << std::endl;
            return;
        }
        std::cout << "The front element is: " << A[index_Beg] << std::endl;
    }

    void end() {
        if (isEmpty()) {
            std::cout << "The queue is empty" << std::endl;
            return;
        }
        std::cout << "The end element is: " << A[index_End] << std::endl;
    }

    bool isEmpty() {
        return (index_Beg == -1 && index_End == -1);
    }

    bool isFull() {
        return ((index_End + 1) % index_size == index_Beg);
    }

private:
    ElementaryType* A;
    size_t index_size;
    size_t index_Beg;
    size_t index_End;
};
