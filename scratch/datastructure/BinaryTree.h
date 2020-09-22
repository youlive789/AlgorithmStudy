#pragma once
#include <iostream>
#include <queue>

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

    void insert(Node* node, const int& value) {

        std::queue<Node*> q;
        q.push(node);

        Node* cursor;
        while (!q.empty()) {
            cursor = q.front();
            q.pop();

            if (cursor->left != nullptr) {
                q.push(cursor->left);
            }
            else {
                cursor->left = new Node(value);
                break;
            }
            
            if (cursor->right != nullptr) {
                q.push(cursor->right);
            }
            else {
                cursor->right = new Node(value);
                break;
            }
        }
        return;
    }

    Node* findPreorderTraversal(Node* cursor, const int& value) {
        if (cursor != nullptr) {
            if (cursor->value == value) {
                return cursor;
            }
            
            Node* left = this->findPreorderTraversal(cursor->left, value);
            Node* right = this->findPreorderTraversal(cursor->right, value);

            if (left != nullptr && right == nullptr) {
                return left;
            }
            else if (left == nullptr && right != nullptr) {
                return right;
            }
            else {
                return nullptr;
            }
        }
        else {
            return nullptr;
        }
    }

    void printPreorderTraversal(Node* cursor) {
        if (cursor != nullptr) {
            std::cout << cursor->value << " ";
            this->printPreorderTraversal(cursor->left);
            this->printPreorderTraversal(cursor->right);
        }
    }

    void printInorderTraversal(Node* cursor) {
        if (cursor != nullptr) {
            this->printInorderTraversal(cursor->left);
            std::cout << cursor->value << " ";
            this->printInorderTraversal(cursor->right);
        }
    }

    void printPostorderTraversal(Node* cursor) {
        if (cursor != nullptr) {
            this->printPostorderTraversal(cursor->left);
            this->printPostorderTraversal(cursor->right);
            std::cout << cursor->value << " ";
        }
    }

public:
    BinaryTree() {}

    void insertNode(const int& value) {
        if (this->head == nullptr) {
            this->head = new Node(value);
            return;
        }
        this->insert(this->head, value);
    }

    void printTree(const int& order) {
        switch (order) {
            case 0: this->printPreorderTraversal(this->head); break;
            case 1: this->printInorderTraversal(this->head); break;
            case 2: this->printPostorderTraversal(this->head); break;
            default: break;
        }
        std::cout << std::endl;
    }

    Node* findNode(const int& value) {
        return this->findPreorderTraversal(this->head, value);
    }
};