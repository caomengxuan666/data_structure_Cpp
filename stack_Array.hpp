#pragma once
#include<iostream>
using namespace std;

template<class ElementaryType = size_t>
class stack_Array {
public:

    stack_Array() : m_size(10), m_top(-1) {//Ĭ���޲ι���
        A = new ElementaryType[m_size];
    }

    stack_Array(int size) : m_size(size), m_top(-1) {//�вΰ汾
        A = new ElementaryType[m_size];
    }

    ~stack_Array() {
        delete[] A;
    }


    void reverse(size_t size) {//�ֶ�ָ������
        ElementaryType* temp = new ElementaryType[size];
        for (size_t i = 0; i <= m_top; i++) {
            temp[i] = A[i];
        }
        delete[] A;
        A = temp;
        m_size =size;
    }

    size_t push(ElementaryType val) {
        bool flag = isFull();
        if (flag==true) {
            reverse();
        }
        m_top++;
        A[m_top] = val;
        return m_top;
    }

    size_t pop() {
        bool flag = isEmpty();
        if (flag) {
            cout << "POP ERROR:The stack is empty" << endl;
            return -1;
        }
        m_top--;
        return m_top;
    }

    size_t getSize() {
        return this->m_size;
    }

    size_t top() {
        bool flag = isEmpty();
            if (flag) {
                cout << "TOP ERROR:The stack is empty" << endl;
                return -1;
            }
            int topNum = A[m_top];
        cout << "The element at the top of the stack is: " << topNum << endl;
        return topNum;
    }

    bool isEmpty() {
        if (this->m_top == -1) {
            return true;
        }
        return false;
    }
private:

    bool isFull() {
        if (this->m_top+1== m_size) {//��Ϊm_top���ȱ���Ϊ-1
            return true;
        }
        return false;
    }



    void reverse() {//�Զ�����
        ElementaryType* temp = new ElementaryType[m_size * 2];
        for (size_t i = 0; i <= m_top; i++) {
            temp[i] = A[i];
        }
        delete[] A;
        A = temp;
        m_size *= 2;
    }

    size_t m_size;
    size_t m_top;
    ElementaryType* A;
};
