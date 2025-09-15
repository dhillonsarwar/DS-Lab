#include <iostream>
#define MAX 20
using namespace std;

class Queue {
    int front;
    int rear;
    int arr[MAX];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
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

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = rear = -1; // queue becomes empty
        } else {
            front++;
        }
        return val;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
};

// Function to interleave using only enqueue/dequeue
void interleaveQueue(Queue &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements, cannot interleave!" << endl;
        return;
    }

    int half = n / 2;
    Queue firstHalf;

    // Move first half elements into firstHalf queue
    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q.dequeue());
    }

    // Interleave by dequeuing from both
    while (!firstHalf.isEmpty()) {
        q.enqueue(firstHalf.dequeue()); // element from first half
        q.enqueue(q.dequeue());         // element from second half
    }
}

int main() {
    Queue q;
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);

    cout << "Original Queue: ";
    q.display();

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}
