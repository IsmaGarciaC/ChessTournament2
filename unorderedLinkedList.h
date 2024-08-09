#include <iterator>

template <class Type>
class unorderedLinkedList {
private:
    struct Node {
        Type data;
        Node* next;
    };
    Node* first;

public:
    unorderedLinkedList() : first(nullptr) {}

    class iterator {
    private:
        Node* current;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = Type;
        using difference_type = std::ptrdiff_t;
        using pointer = Type*;
        using reference = Type&;

        iterator(Node* node) : current(node) {}

        reference operator*() const { return current->data; }
        pointer operator->() { return &current->data; }

        iterator& operator++() {
            current = current->next;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const iterator& a, const iterator& b) {
            return a.current == b.current;
        }
        friend bool operator!=(const iterator& a, const iterator& b) {
            return a.current != b.current;
        }
    };

    iterator begin() { return iterator(first); }
    iterator end() { return iterator(nullptr); }
    iterator begin() const { return iterator(first); }
    iterator end() const { return iterator(nullptr); }

    void insertLast(const Type& data) {
        Node* newNode = new Node{data, nullptr};
        if (!first) {
            first = newNode;
        } else {
            Node* temp = first;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
};
