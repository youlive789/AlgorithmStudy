#pragma once
#include "LinkedList.h"

template<typename T>
class Queue {
private:
    int size;
    LinkedList<T>* container;
public:
    Queue() {
        this->size = 0;
        this->container = new LinkedList<T>();
    }

    void push(T element) {
        this->container->add(element);
    }

    T top() {
        return this->container->get(0);
    }

    void pop() {
        this->container->remove(0);
    }

    ~Queue() {
        delete this->container;
    }
};