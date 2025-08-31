#include <iostream>
using namespace std;
#define MAX 100
class Stack {
    int arr[MAX], top;
public:
    Stack() { top = -1; }
    void push(int x) {
        if (top == MAX - 1) return;
        arr[++top] = x;
    }
    void pop() {
        if (top == -1) return;
        top--;
    }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void display() {
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
    void peek() {
        if (top != -1) cout << arr[top] << endl;
    }
};
int main() {
    Stack s; int ch, val;
    while(ch != 7) {
        cout << "1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cin >> ch;
        switch(ch) {
            case 1: cin >> val; s.push(val); break;
            case 2: s.pop(); break;
            case 3: cout << (s.isEmpty() ? "Yes" : "No") << endl; break;
            case 4: cout << (s.isFull() ? "Yes" : "No") << endl; break;
            case 5: s.display(); break;
            case 6: s.peek(); break;
        }
    } }
