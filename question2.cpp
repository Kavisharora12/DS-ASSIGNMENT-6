#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}
    void insertAtEnd(int val) {
        Node* n = new Node{val, nullptr};
        if (!head) { head = n; head->next = head; return; }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = n; n->next = head;
    }
    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);
    cll.display();
}
