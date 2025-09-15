#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

class Queue {
    int front;
    int rear;
    char arr[MAX];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(char val) {
        if (rear == MAX - 1) {
            cout << "Queue overflow" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = val;
    }

    char dequeue() {
        if (isEmpty()) {
            return '\0';
        }
        char val = arr[front];
        if (front == rear) {
            front = rear = -1; // empty
        } else {
            front++;
        }
        return val;
    }

    bool isEmpty() {
        return (front == -1);
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};

// Function to process the stream
void firstNonRepeating(string s) {
    Queue q;
    int freq[26] = {0}; // only for lowercase a-z

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch == ' ') continue; // ignore spaces (as per sample input)

        // update frequency and push to queue
        freq[ch - 'a']++;
        q.enqueue(ch);

        // remove all repeating characters from front
        while (!q.isEmpty() && freq[q.peek() - 'a'] > 1) {
            q.dequeue();
        }

        // print result
        if (q.isEmpty())
            cout << -1 << " ";
        else
            cout << q.peek() << " ";
    }
    cout << endl;
}

int main() {
    string s = "a a b c";  // sample input

    cout << "Input String: " << s << endl;
    cout << "First Non-Repeating Output: ";
    firstNonRepeating(s);

    return 0;
}
