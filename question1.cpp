#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}
    void insertAtBeginning(int val) {
        Node* n = new Node{val, nullptr, nullptr};
        if (!head) { head = n; head->next = head; return; }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        n->next = head; temp->next = n; head = n;
    }
    void insertAtEnd(int val) {
        Node* n = new Node{val, nullptr, nullptr};
        if (!head) { head = n; head->next = head; return; }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = n; n->next = head;
    }
    void insertAfter(int key, int val) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* n = new Node{val, temp->next, nullptr};
                temp->next = n; return;
            }
            temp = temp->next;
        } while (temp != head);
    }
    void deleteNode(int key) {
        if (!head) return;
        Node* curr = head; Node* prev = nullptr;
        if (head->data == key) {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            if (temp == head) { delete head; head = nullptr; return; }
            temp->next = head->next; Node* del = head;
            head = head->next; delete del; return;
        }
        do {
            prev = curr; curr = curr->next;
            if (curr->data == key) { prev->next = curr->next; delete curr; return; }
        } while (curr != head);
    }
    void search(int key) {
        if (!head) { cout << "Empty\n"; return; }
        Node* t = head; int pos = 1;
        do {
            if (t->data == key) { cout << "Found at " << pos << endl; return; }
            t = t->next; pos++;
        } while (t != head);
        cout << "Not found\n";
    }
    void display() {
        if (!head) { cout << "Empty\n"; return; }
        Node* t = head;
        do { cout << t->data << " "; t = t->next; } while (t != head);
        cout << endl;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}
    void insertAtBeginning(int val) {
        Node* n = new Node{val, head, nullptr};
        if (head) head->prev = n;
        head = n;
    }
    void insertAtEnd(int val) {
        Node* n = new Node{val, nullptr, nullptr};
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n; n->prev = t;
    }
    void insertAfter(int key, int val) {
        Node* t = head;
        while (t) {
            if (t->data == key) {
                Node* n = new Node{val, t->next, t};
                if (t->next) t->next->prev = n;
                t->next = n; return;
            }
            t = t->next;
        }
    }
    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) { insertAtBeginning(val); return; }
        Node* t = head;
        while (t) {
            if (t->data == key) {
                Node* n = new Node{val, t, t->prev};
                t->prev->next = n; t->prev = n; return;
            }
            t = t->next;
        }
    }
    void deleteNode(int key) {
        Node* t = head;
        while (t) {
            if (t->data == key) {
                if (t->prev) t->prev->next = t->next;
                else head = t->next;
                if (t->next) t->next->prev = t->prev;
                delete t; return;
            }
            t = t->next;
        }
    }
    void search(int key) {
        Node* t = head; int pos = 1;
        while (t) {
            if (t->data == key) { cout << "Found at " << pos << endl; return; }
            t = t->next; pos++;
        }
        cout << "Not found\n";
    }
    void display() {
        Node* t = head;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    DoublyLinkedList dll;
    int choice, val, key, listChoice;
    do {
        cout << "1.Circular\n2.Doubly\n0.Exit\n"; cin >> listChoice;
        if (listChoice == 1) {
            do {
                cout << "1.IB 2.IE 3.IA 4.D 5.S 6.Disp 0.Back\n"; cin >> choice;
                switch (choice) {
                    case 1: cin >> val; cll.insertAtBeginning(val); break;
                    case 2: cin >> val; cll.insertAtEnd(val); break;
                    case 3: cin >> key >> val; cll.insertAfter(key, val); break;
                    case 4: cin >> key; cll.deleteNode(key); break;
                    case 5: cin >> val; cll.search(val); break;
                    case 6: cll.display(); break;
                }
            } while (choice != 0);
        }
        else if (listChoice == 2) {
            do {
                cout << "1.IB 2.IE 3.IA 4.IBf 5.D 6.S 7.Disp 0.Back\n"; cin >> choice;
                switch (choice) {
                    case 1: cin >> val; dll.insertAtBeginning(val); break;
                    case 2: cin >> val; dll.insertAtEnd(val); break;
                    case 3: cin >> key >> val; dll.insertAfter(key, val); break;
                    case 4: cin >> key >> val; dll.insertBefore(key, val); break;
                    case 5: cin >> key; dll.deleteNode(key); break;
                    case 6: cin >> val; dll.search(val); break;
                    case 7: dll.display(); break;
                }
            } while (choice != 0);
        }
    } while (listChoice != 0);
}
