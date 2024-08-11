#pragma once

// Node structure 
template <typename T>
struct Node {
    T data;
    Node<T>* next; // Pointer to the next node in the list
    Node(const T& item) : data(item), next(nullptr) {}
};

// Unordered linked list class
template <typename T>
class unorderedLinkedList {
private:
    Node<T>* head; // Pointer to the first node 
    Node<T>* tail; // Pointer to the last node

public:
    // Constructor initializing the head and tail to nullptr
    unorderedLinkedList() : head(nullptr), tail(nullptr) {}
    
    // Method to insert a new item at the end of the list
    void insertLast(const T& newItem) {
        Node<T>* newNode = new Node<T>(newItem);
        if (tail) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
    }

    // Method to get the beginning of the list
    Node<T>* begin() const {
        return head;
    }

    // Method to get the end of the list (nullptr in this case)
    Node<T>* end() const {
        return nullptr;
    }
};
