//
// Created by 12043 on 28.11.2017.
//

#ifndef ODEV3_LINKEDLIST_H
#define ODEV3_LINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template<typename T>
class LinkedList {
private:
    Node<T> *first;
    int length;

    inline bool invalidIndex(int index) {
        return (index >= length || index < 0);
    }

    Node<T> *getLast() {
        Node<T> *temp = first;

        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }

        return temp;
    }

    Node<T> *getBefore(int index) {
        if (invalidIndex(index)) {
            cout << "Hata var!\n";
            // TODO hata firlat
        }

        Node<T> *temp = first;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->getNext();
        }

        return temp;
    }

public:
    LinkedList() {
        first = nullptr;
        length = 0;
    }

    ~LinkedList() {

    }

    void append(const T &data) {
        Node<T> *newNode = new Node<T>();
        newNode->setData(data);
        if (length == 0) {
            first = newNode;
        } else {
            getLast()->setNext(newNode);
        }
        length++;
    }

    void prepend(const T &data) {
        Node<T> *newNode = new Node<T>();
        newNode->setData(data);
        newNode->setNext(first);
        first = newNode;
        length++;
    }

    T &get(int index) {
        if (invalidIndex(index)) {
            cout << "Hata var!\n";
            // TODO hata firlat
        }

        Node<T> *temp = first;
        for (int i = 0; i < length; ++i) {
            if (i == index) {
                return (temp->getData());
            }

            temp = temp->getNext();
        }
    }

    void remove(int index) {
        if (invalidIndex(index)) {
            cout << "Hata var!\n";
            // TODO hata firlat
        }

        if (index != 0) {
            Node<T> *beforeItem = getBefore(index);
            Node<T> *afterItem = beforeItem->getNext()->getNext();
            delete beforeItem->getNext();
            beforeItem->setNext(afterItem);
        } else {
            Node<T> *temp = first->getNext();
            delete first;
            first = temp;
        }

        length--;
    }

    void clear() {
        while (length > 0) {
            remove(0);
            // ya da
            // remove(length - 1);
        }
    }

    int getLength() {
        return this->length;
    }
};


#endif //ODEV3_LINKEDLIST_H
