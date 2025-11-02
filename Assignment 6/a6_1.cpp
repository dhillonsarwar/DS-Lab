#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node(int v) : data(v), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
    Node* head = nullptr;
public:
    void insertBeg(int v) {
        Node* n = new Node(v);
        if (head) { n->next = head; head->prev = n; }
        head = n;
    }
    void insertEnd(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; return; }
        Node* t = head; while (t->next) t = t->next;
        t->next = n; n->prev = t;
    }
    void insertAfter(int k, int v) {
        Node* t = head; while (t && t->data != k) t = t->next;
        if (!t) return;
        Node* n = new Node(v);
        n->next = t->next; n->prev = t;
        if (t->next) t->next->prev = n;
        t->next = n;
    }
    void insertBefore(int k, int v) {
        if (head && head->data == k) { insertBeg(v); return; }
        Node* t = head; while (t && t->data != k) t = t->next;
        if (!t) return;
        Node* n = new Node(v);
        n->next = t; n->prev = t->prev;
        t->prev->next = n;
        t->prev = n;
    }
    void delNode(int k) {
        Node* t = head; while (t && t->data != k) t = t->next;
        if (!t) return;
        if (t->prev) t->prev->next = t->next; else head = t->next;
        if (t->next) t->next->prev = t->prev;
        delete t;
    }
    void search(int k) {
        Node* t = head; int pos = 1;
        while (t) {
            if (t->data == k) { cout << "Found at " << pos << "\n"; return; }
            t = t->next; pos++;
        }
        cout << "Not found\n";
    }
    void display() {
        for (Node* t = head; t; t = t->next) cout << t->data << " ";
        cout << "\n";
    }
};

class CircularLinkedList {
    Node* head = nullptr;
public:
    void insertBeg(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; head->next = head; return; }
        Node* t = head; while (t->next != head) t = t->next;
        t->next = n; n->next = head; head = n;
    }
    void insertEnd(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; head->next = head; return; }
        Node* t = head; while (t->next != head) t = t->next;
        t->next = n; n->next = head;
    }
    void insertAfter(int k, int v) {
        Node* t = head;
        if (!t) return;
        do {
            if (t->data == k) {
                Node* n = new Node(v);
                n->next = t->next;
                t->next = n;
                return;
            }
            t = t->next;
        } while (t != head);
    }
    void insertBefore(int k, int v) {
        if (!head) return;
        Node* t = head; Node* p = nullptr;
        do {
            if (t->data == k) {
                Node* n = new Node(v);
                if (!p) {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    last->next = n;
                    n->next = head;
                    head = n;
                } else {
                    p->next = n;
                    n->next = t;
                }
                return;
            }
            p = t;
            t = t->next;
        } while (t != head);
    }
    void delNode(int k) {
        if (!head) return;
        Node *t = head, *p = nullptr;
        do {
            if (t->data == k) {
                if (!p) {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    if (last == head) head = nullptr;
                    else { last->next = head->next; head = head->next; }
                } else p->next = t->next;
                delete t; return;
            }
            p = t; t = t->next;
        } while (t != head);
    }
    void search(int k) {
        if (!head) { cout << "Not found\n"; return; }
        Node* t = head; int pos = 1;
        do {
            if (t->data == k) { cout << "Found at " << pos << "\n"; return; }
            t = t->next; pos++;
        } while (t != head);
        cout << "Not found\n";
    }
    void display() {
        if (!head) { cout << "Empty\n"; return; }
        Node* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int listType, ch, v, k;

    while (true) {
        cout << "\n1. DoublyLinkedList\n2. CircularLinkedList\n3. Exit\nChoose: ";
        cin >> listType;

        if (listType == 3) break;

        while (true) {
            cout << "1.InsBeg 2.InsEnd 3.InsAfter 4.InsBefore 5.Delete 6.Search 7.Display 8.Back\nChoice: ";
            cin >> ch;

            if (ch == 8) break;

            switch (listType) {
                case 1: { // Doubly Linked List
                    switch (ch) {
                        case 1: cout << "Val: "; cin >> v; dll.insertBeg(v); break;
                        case 2: cout << "Val: "; cin >> v; dll.insertEnd(v); break;
                        case 3: cout << "Key: "; cin >> k; cout << "Val: "; cin >> v; dll.insertAfter(k, v); break;
                        case 4: cout << "Key: "; cin >> k; cout << "Val: "; cin >> v; dll.insertBefore(k, v); break;
                        case 5: cout << "Key: "; cin >> k; dll.delNode(k); break;
                        case 6: cout << "Key: "; cin >> k; dll.search(k); break;
                        case 7: dll.display(); break;
                        default: cout << "Invalid choice!\n";
                    }
                    break;
                }
                case 2: { // Circular Linked List
                    switch (ch) {
                        case 1: cout << "Val: "; cin >> v; cll.insertBeg(v); break;
                        case 2: cout << "Val: "; cin >> v; cll.insertEnd(v); break;
                        case 3: cout << "Key: "; cin >> k; cout << "Val: "; cin >> v; cll.insertAfter(k, v); break;
                        case 4: cout << "Key: "; cin >> k; cout << "Val: "; cin >> v; cll.insertBefore(k, v); break;
                        case 5: cout << "Key: "; cin >> k; cll.delNode(k); break;
                        case 6: cout << "Key: "; cin >> k; cll.search(k); break;
                        case 7: cll.display(); break;
                        default: cout << "Invalid choice!\n";
                    }
                    break;
                }
                default:
                    cout << "Invalid list type!\n";
            }
        }
    }

    return 0;
}
