#pragma once

template <typename T>
class Node {
private:
    T data;
    Node* left;
    Node* right;
public:
    Node(T data) : data(data) {}
    ~Node() {}
};

template <typename T>
class Heap {
private:
    Node* root;
    void heapify() {}
public:
    Heap() {}

    void insert(T data) {
        if (!this->root) {
            this->root = new Node(data);
            return;
        }
    }

    T top() {

    }

    ~Heap() {}
};