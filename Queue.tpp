template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(const T& newData) {
    Node* newNode = new Node(newData);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

template <typename T>
void Queue<T>::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr) {
        rear = nullptr; // Reset rear if queue becomes empty
    }
}

template <typename T>
T& Queue<T>::getFront() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty. No front element.");
    }
    return front->data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == nullptr;
}

template <typename T>
void Queue<T>::displayQueue() const {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    std::cout << "Queue elements:" << std::endl;
    Node* current = front;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
