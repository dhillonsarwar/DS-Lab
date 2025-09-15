#include <iostream>
#define MAX 5
using namespace std;
class Queue
{

    int front;
    int rear;
    int arr[MAX];

public:
    Queue()
    {

        rear = -1;
        front = -1;
    }
    void enqueue(int val)
    {
        if (front == (rear + 1) % MAX)
        {
            cout << "queue overflow" << endl;
            return;
        }
        if (front == -1)
        {
            rear = front = 0;
            arr[rear] = val;

            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = val;
    }
    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
            front = (front + 1) % MAX;
    }
    bool isEmpty()
    {
        if (front == -1)
            return 1;
        else
            return 0;
    }
    bool isFull()
    {
        return (front == (rear + 1) % MAX);
    }
    int peek()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        return arr[front];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue empty" << endl;
            return;
        }
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
    int size()
    {
        if (front == -1)
            return 0;
        if (rear >= front)
            return rear - front + 1;
        else
            return MAX - (front - rear - 1);
    }
};
int main()
{
    Queue q;
    int choice, val;

    do
    {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Size\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            cout << "Front element: " << q.peek() << endl;
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                cout << "Queue is empty\n";
            else
                cout << "Queue is not empty\n";
            break;
        case 6:
            if (q.isFull())
                cout << "Queue is full\n";
            else
                cout << "Queue is not full\n";
            break;
        case 7:
            cout << "Queue size: " << q.size() << endl;
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}