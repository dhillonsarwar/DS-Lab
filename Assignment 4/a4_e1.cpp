#include <iostream>
#include <queue>
using namespace std;

void printBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");
    while (n--) {
        string current = q.front();
        q.pop();
        cout << current << " ";
        q.push(current + "0");
        q.push(current + "1");
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    printBinaryNumbers(n);
    return 0;
}
