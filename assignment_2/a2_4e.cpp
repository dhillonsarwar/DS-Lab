#include <iostream>
using namespace std;

int main() {
    char text[20];
    cout << "Enter a word: ";
    cin >> text;

    int k = 0;
    while (text[k] != '\0') {
        if (text[k] >= 'A' && text[k] <= 'Z') {
            text[k] = text[k] + 32;
        }
        k++;
    }

    cout << "Converted to lowercase: " << text;
    return 0;
}
