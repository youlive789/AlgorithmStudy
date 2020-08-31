#pragma once
#include "KeyLinkedList.h"
#include <string>

using namespace std;

template <typename T, typename V>
class HashMap {
private:
    KeyLinkedList<T, V>* first = new KeyLinkedList<T, V>();
    KeyLinkedList<T, V>* second = new KeyLinkedList<T, V>();
    KeyLinkedList<T, V>* third = new KeyLinkedList<T, V>();

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
    HashMap() {}

    void put(T key, V value) {
        int hashcode = this->hash(key);
        switch (hashcode)
        {
        case 0:
            this->first->add(key, value);
            break;
        case 1:
            this->second->add(key, value);
            break;
        case 2:
            this->third->add(key, value);
             break;
        default:
            throw "잘못된 키 값입니다.";
        }
    }

    V get(T key) {
        V value;
        int hashcode = this->hash(key);
        switch (hashcode)
        {
        case 0:
            value = this->first->get(key);
            break;
        case 1:
            value = this->second->get(key);
            break;
        case 2:
            value = this->third->get(key);
            break;
        default:
            throw "잘못된 키 값입니다.";
        }

        return value;
    }

    ~HashMap() {
        delete[] first;
        delete[] second;
        delete[] third;
    }
};