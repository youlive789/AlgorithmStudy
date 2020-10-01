#pragma once
#include <iostream>

template <typename T>
class Stack {
private:
    int size; 
    T* container;
    int sizeContainer;

    // 스택 컨테이너의 사이즈를 재조정한다.
    void resizeContainer() {
        this->sizeContainer *= 2;
        T* tmpContainer = new T[this->sizeContainer];
        for (int idx = 0; idx < this->size; idx++) {
            tmpContainer[idx] = this->container[idx];
        }
        delete[] this->container;
        this->container = tmpContainer;
    }

public:
    Stack() {
        this->size = 0;
        this->sizeContainer = 2;
        this->container = new T[this->sizeContainer];
    }

    void push(T element) {
        if (this->sizeContainer == this->size) {
            this->resizeContainer();
        }
        this->size++;
        this->container[this->size - 1] = element;
    }

    bool empty() {
        if (this->size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void pop() {
        if (this->empty()) {
            std::cout << "스택에 원소가 없습니다." << std::endl;
        }
        else {
            this->size--;
        }
    }

    T top() {
        return this->container[this->size - 1];  
    }

    ~Stack() {
        delete[] this->container;
    }
};