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

   
    int countOnes(int n) {
        int cnt = 0;
        while (n) {
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }

  
    void removeEvenParity() {
        Node* temp = head;

        while (temp) {
            int ones = countOnes(temp->data);
            bool evenParity = (ones % 2 == 0);

            if (evenParity) {
                Node* toDelete = temp;
            
                temp = temp->next;

                if (toDelete->prev)
                    toDelete->prev->next = toDelete->next;
                else
                    head = toDelete->next;  

                if (toDelete->next)
                    toDelete->next->prev = toDelete->prev;

                delete toDelete;
            } else {
                temp = temp->next;
            }
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
    int choice, val;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at end\n";
        cout << "2. Display list\n";
        cout << "3. Remove even-parity elements\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertEnd(val);
            break;
        case 2:
            cout << "List: ";
            list.display();
            break;
        case 3:
            list.removeEvenParity();
            cout << "Even-parity elements removed.\n";
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
