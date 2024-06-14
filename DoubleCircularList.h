// DoubleCircularList.h
#ifndef DOUBLECIRCULARLIST_H
#define DOUBLECIRCULARLIST_H

#include <iostream>

template <typename T>
class DoubleCircularList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& newData) : data(newData), next(nullptr), prev(nullptr) {}
    };

    Node* head;

public:
    // Constructor
    DoubleCircularList();

    // Destructor
    ~DoubleCircularList();

    // Methods to manage the list
    void addElement(const T& newData);
    void removeElement(const T& targetData);
    void displayElements() const;
};

#include "DoubleCircularList.tpp"

#endif
