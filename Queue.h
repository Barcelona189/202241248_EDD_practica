#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& newData) : data(newData), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    // Constructor
    Queue();

    // Destructor
    ~Queue();

    // Queue operations
    void enqueue(const T& newData);
    void dequeue();
    T& getFront() const;
    bool isEmpty() const;
    void displayQueue() const;
};

#include "Queue.tpp"

#endif
