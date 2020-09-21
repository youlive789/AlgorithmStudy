#pragma once
#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(const int& value) : value(value) {}
};

class BinaryTree {
private:
    Node* head;

    void insert(Node* cursor, const int& value) {
        if (cursor == nullptr) {
            cursor = new Node(value);
        }
        else {
            
        }
    }

    void inorderTraversal(Node* cursor) {
        if (cursor != nullptr) {
            this->inorderTraversal(cursor->left);
            std::cout << cursor->value << std::endl;
            this->inorderTraversal(cursor->right);
        }
    }

public:
    BinaryTree() {}

    void insertNode(const int& value) {
        this->insert(this->head, value);
    }

    void printTree() {
        this->inorderTraversal(this->head);
    }

    Node* findNode(const int& value) {}
};