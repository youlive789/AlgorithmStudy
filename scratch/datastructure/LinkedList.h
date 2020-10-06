#pragma once

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node<T>* next;
    Node(T value) : value(value) {}
};

template <typename T>
class LinkedList {
private:
    int size = 0;
    Node<T>* head;
public:
    void add(T value) {
        if (this->head) {
            Node<T>* cursor = this->head;
            while (cursor->next) {
                cursor = cursor->next;
            }
            cursor->next = new Node<T>(value);
        }
        else {
            this->head = new Node<T>(value);
        }
        this->size++;
    }

    T get(const int& index) {
        if (index < 0 || index > this->size) {
            throw std::out_of_range("범위초과");
        }

        int idx = 0;
        Node<T>* cursor = this->head;
        while (idx != index) {
            cursor = cursor->next;
            idx++;
        }

        return cursor->value;
    }

    void remove(const int& index) {
        if (index < 0 || index > this->size) {
            throw std::out_of_range("범위초과");
        }
        if (this->size == 0) return;

        if (index == 0) {
            Node<T>* cursor = this->head;
            this->head = this->head->next;
            delete cursor;
        }
        else {
            int idx = 0;
            Node<T>* cursor = this->head;
            while (idx != index - 1) {
                cursor = cursor->next;
                idx++;
            }

            Node<T>* tmp = cursor->next;
            cursor->next = cursor->next->next;
            delete tmp;
        }

        this->size--;
    }

    int length() {
        return this->size;
    }
};

