#pragma once
#include <iostream>

template <typename T>
class ArrayList {
private:
    int currentSize = 0;
    int containerSize = 2;
    T* container;
public:
    ArrayList() {
        this->container = new T[this->containerSize];
    }

    void add(const T& element) {
        // 사이즈 늘리기
        if (this->currentSize >= this->containerSize) {
            this->containerSize *= 2;
            T* tmp = new T[this->containerSize];

            int idx = 0;
            for (int i = 0; i < this->currentSize; i++) {
                tmp[idx] = this->container[i];
                idx++;
            }

            delete[] this->container;
            this->container = tmp;
        }

        this->container[this->currentSize] = element;
        this->currentSize++;
    }

    T get(const int& index) {
        return this->container[index];
    }
    
    int size() {
        return currentSize;
    }

    ~ArrayList() {
        delete[] container;
    }
};