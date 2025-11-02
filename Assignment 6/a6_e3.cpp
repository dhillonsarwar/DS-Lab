#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node(int x) { data = x; next = nullptr; prev = nullptr; }
};

Node* reverseInGroups(Node* head, int k) {
    if (!head) return head;
    Node *curr = head, *newHead = nullptr, *tail = nullptr;
    while (curr) {
        Node *groupHead = curr, *prev = nullptr, *next = nullptr;
        int count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            curr->prev = nullptr;
            if (prev) prev->prev = curr;
            prev = curr;
            curr = next;
            count++;
        }
        if (!newHead) newHead = prev;
        if (tail) { tail->next = prev; prev->prev = tail; }
        tail = groupHead;
    }
    return newHead;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    head = reverseInGroups(head, 2);
    printList(head);
}
