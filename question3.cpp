#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}
    void insert(int val) {
        Node* n = new Node{val, nullptr, nullptr};
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n; n->prev = t;
    }
    int size() {
        int c = 0; Node* t = head;
        while (t) { c++; t = t->next; }
        return c;
    }
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}
    void insert(int val) {
        Node* n = new Node{val, nullptr, nullptr};
        if (!head) { head = n; head->next = head; return; }
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = n; n->next = head;
    }
    int size() {
        if (!head) return 0;
        int c = 0; Node* t = head;
        do { c++; t = t->next; } while (t != head);
        return c;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insert(10); dll.insert(20); dll.insert(30);
    cout << "Size of Doubly Linked List: " << dll.size() << endl;

    CircularLinkedList cll;
    cll.insert(5); cll.insert(15); cll.insert(25); cll.insert(35);
    cout << "Size of Circular Linked List: " << cll.size() << endl;
}
