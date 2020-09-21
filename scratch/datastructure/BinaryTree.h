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
        // queue를 이용해서 inorder 순서로 삽입하기
    }

    void preorderTraversal(Node* cursor) {
        if (cursor != nullptr) {
            std::cout << cursor->value << std::endl;
            this->preorderTraversal(cursor->left);
            this->preorderTraversal(cursor->right);
        }
    }

public:
    BinaryTree() {}

    void insertNode(const int& value) {
        this->insert(this->head, value);
    }

    void printTree() {
        this->preorderTraversal(this->head);
    }

    Node* findNode(const int& value) {}
};