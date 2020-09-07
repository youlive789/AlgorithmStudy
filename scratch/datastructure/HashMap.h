#pragma once
#include "KeyLinkedList.h"
#include <string>

using namespace std;

template <typename T, typename V>
class HashMap {
private:
    KeyLinkedList<T, V>* container[3];

    int hash(T key) {
        int hashValue = -1;
        int tmp = 0;
        
        for (char c : key) {
            tmp += (int)c;
        }
        hashValue = tmp % 3;

        return hashValue;
    }

public:
    HashMap() {
        for (int i = 0; i < 3; i++) {
            container[i] = new KeyLinkedList<T, V>();
        }
    }

    void put(T key, V value) {
        int hashcode = this->hash(key);

        Node<T, V>* cursor = this->container[hashcode]->head;
        while (cursor != nullptr) {
            if (cursor->key == key) {
                break;
            }
            cursor = cursor->next;
        }

        // 해쉬코드 컨테이너에 키가 있다면
        if (cursor != nullptr) {
            // 덮어쓰기
            cursor->value = value;
        }
        // 없다면
        else {
            // 컨테이너에 노드추가
            this->container[hashcode]->add(key, value);
        }
    }

    V get(T key) {
        V value;
        int hashcode = this->hash(key);

        Node<T, V>* cursor = this->container[hashcode]->head;
        while (cursor != nullptr) {
            if (cursor->key == key) {
                break;
            }
            cursor = cursor->next;
        }

        // 해쉬코드 컨테이너에 키가 있다면
        if (cursor != nullptr) {
            // 값 리턴
            return cursor->value;
        }
        // 없다면
        else {
            throw "키를 찾을 수 없습니다.";
        }
    }

    ~HashMap() {
        delete[] this->container;
    }
};