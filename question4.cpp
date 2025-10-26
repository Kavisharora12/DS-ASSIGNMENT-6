#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void insert(char c) {
        Node* n = new Node{c, nullptr, nullptr};
        if (!head) { head = tail = n; return; }
        tail->next = n; n->prev = tail; tail = n;
    }
    bool isPalindrome() {
        Node* left = head;
        Node* right = tail;
        while (left && right && left != right && right->next != left) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    string s = "LEVEL";
    for (char c : s) dll.insert(c);
    cout << (dll.isPalindrome() ? "True" : "False") << endl;
}
