#pragma once
#include <queue>
#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(const int& value) : value(value) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* _find(Node* cursor, const int& value) {
        if (!cursor) {
            return nullptr;
        }

        if (cursor->value == value) {
            return cursor;
        }
        else {
            if (cursor->value > value) {
                return _find(cursor->left, value);
            }
            else {
                return _find(cursor->right, value);
            }
        }
    }

    void _insert(Node* cursor, const int& value) {
        if (cursor->value == value) {
            std::cout << "이미 있는 값입니다." << std::endl;
            return;
        }
        else if (cursor->value > value) {
            if (cursor->left) {
                this->_insert(cursor->left, value);
            }
            else {
                cursor->left = new Node(value);
                return;
            }
        }
        else if (cursor->value < value) {
            if (cursor->right) {
                this->_insert(cursor->right, value);
            }
            else {
                cursor->right = new Node(value);
                return;
            }
        }
    }

    void _preorderTraversal(Node* cursor) {
        if (!cursor) {
            return;
        }
        
        std::cout << cursor->value << std::endl;
        this->_preorderTraversal(cursor->left);
        this->_preorderTraversal(cursor->right);
    }

public:
    void insert(const int& value) {
        if (!this->root) {
            this->root = new Node(value);
            return;
        }

        this->_insert(this->root, value);
    }

    Node* find(const int& value) {
        Node* cursor = this->root;
        if (!cursor) {
            return nullptr;
        }
        return this->_find(cursor, value);
    }

    void remove(const int& value) {}

    void printTree() {
        this->_preorderTraversal(this->root);
    }
};