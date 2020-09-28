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
        else {
            Node* parent;
            while (cursor) {
                parent = cursor;
                if (parent->value > value) {
                    cursor = cursor->left;
                }
                else {
                    cursor = cursor->right;
                }
            }
            if (parent->value > value) {
                parent->left = new Node(value);
            }
            else {
                parent->right = new Node(value);
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

    void printTree() {
        this->_preorderTraversal(this->root);
    }
};