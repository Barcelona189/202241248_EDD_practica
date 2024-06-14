template <typename T>
DoubleCircularList<T>::DoubleCircularList() : head(nullptr) {}

template <typename T>
DoubleCircularList<T>::~DoubleCircularList() {
    if (head != nullptr) {
        Node* current = head;
        do {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
}

template <typename T>
void DoubleCircularList<T>::addElement(const T& newData) {
    Node* newNode = new Node(newData);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

template <typename T>
void DoubleCircularList<T>::removeElement(const T& targetData) {
    if (head == nullptr) return;

    Node* current = head;
    do {
        if (current->data == targetData) {
            if (current == head && current->next == head) {
                delete head;
                head = nullptr;
            } else {
                Node* prevNode = current->prev;
                Node* nextNode = current->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                if (current == head) {
                    head = nextNode;
                }
                delete current;
            }
            return;
        }
        current = current->next;
    } while (current != head);
}

template <typename T>
void DoubleCircularList<T>::displayElements() const {
    if (head == nullptr) {
        std::cout << "No elements in the list." << std::endl;
        return;
    }

    Node* current = head;
    do {
        current->data.displayInfo();
        std::cout << "------------------------" << std::endl;
        current = current->next;
    } while (current != head);
}
