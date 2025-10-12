#include <iostream>
#include <queue>
#include <climits>
using namespace std;

void sortQueue(queue<int>& q) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        int minValue = INT_MAX;
        int count = q.size();

        for (int j = 0; j < count; j++) {
            int num = q.front();
            q.pop();
            if (num < minValue) minValue = num;
            q.push(num);
        }

        bool removed = false;
        for (int j = 0; j < count; j++) {
            int num = q.front();
            q.pop();
            if (num == minValue && !removed) {
                removed = true;
                continue;
            }
            q.push(num);
        }

        q.push(minValue);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    cout << "Sorted queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
