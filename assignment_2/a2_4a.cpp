#include <iostream>
using namespace std;

int main() {
    char a[100], b[100];

    cout << "Enter first string: ";
    cin >> a;
    cout << "Enter second string: ";
    cin >> b;

    int lenA = 0, lenB = 0;

    for (int i = 0; a[i] != '\0'; i++) {
        lenA++;
    }

    for (int j = 0; b[j] != '\0'; j++) {
        lenB++;
    }

    char join[200];
    int pos = 0;

    for (int i = 0; i < lenA; i++) {
        join[pos++] = a[i];
    }

    for (int j = 0; j < lenB; j++) {
        join[pos++] = b[j];
    }

    join[pos] = '\0';

    cout << "Final string: " << join << endl;

    return 0;
}
