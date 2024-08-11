// unorderedLinkedList.h
#pragma once

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(const T& item) : data(item), next(nullptr) {}
};

template <typename T>
class unorderedLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    unorderedLinkedList() : head(nullptr), tail(nullptr) {}
    
    void insertLast(const T& newItem) {
        Node<T>* newNode = new Node<T>(newItem);
        if (tail) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
    }

    Node<T>* begin() const {
        return head;
    }

    Node<T>* end() const {
        return nullptr;
    }
};
