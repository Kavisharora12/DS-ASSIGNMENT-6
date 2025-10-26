#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    void insert(int val) {
        Node* n = new Node{val, nullptr};
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
    void makeCircular() {
        if (!head) return;
        Node* t = head;
        while (t->next) t = t->next;
        t->next = head;
    }
    bool isCircular() {
        if (!head) return false;
        Node* t = head->next;
        while (t && t != head) t = t->next;
        return t == head;
    }
};

int main() {
    LinkedList list;
    list.insert(2);
    list.insert(4);
    list.insert(6);
    list.insert(7);
    list.insert(5);
    list.makeCircular();
    cout << (list.isCircular() ? "True" : "False") << endl;
}
