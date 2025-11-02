#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node(int v) : data(v), next(nullptr), prev(nullptr) {}
};

class DLL {
    Node* head;
public:
    DLL() : head(nullptr) {}

    void insertEnd(int v) {
        Node* n = new Node(v);
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    

   

    void correctPointer() {
        if (!head)
            return;
        Node* temp = head;
        while (temp->next != NULL) {
            if (temp->next->prev != temp)
                temp->next->prev = temp;
            temp = temp->next;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DLL list;
   correctPointer();
return 0;}
