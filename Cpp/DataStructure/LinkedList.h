#pragma once

class Node {
public:
    int data;
    Node * next;
    Node(int data) : data(data) {}
};

class LinkdedList {
private:
    Node * head = nullptr;
public:

    LinkdedList() {}

    void insertNode(Node* node) {
        // 처음 삽입 시
        if (this->head == nullptr) {
            this->head = node;
            return;
        }
        // 그 외의 경우
        Node* cursor = this->head;
        while (cursor->next != nullptr) {
            cursor = cursor->next;
        }
        cursor->next = node;
    }

    void deleteNode(const int& idx) {

        if (idx == 0) {
            this->head = this->head->next;
            return;
        }

        int index = 0;
        Node* cursor = this->head;
        while (index != idx - 2) {
            cursor = cursor->next;
            index++;
        }

        Node* nextNode = cursor->next->next;
        cursor->next = nextNode;
    }

    int getNode(const int& idx) {
        int index = 0;
        Node* cursor = this->head;
        while (index != idx) {
            cursor = cursor->next;
            index++;
        }

        return cursor->data;
    }

    void printList() {
        Node * cursor = this->head;
        while (cursor != nullptr) {
            std::cout << cursor->data << std::endl;
            cursor = cursor->next;
        }
    }
};


