#include <iostream>
using namespace std;

int main() {
    char text[20];
    cout << "Enter any word: ";
    cin >> text;

    int size = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        size++;
    }

    for (int left = 0, right = size - 1; left < right; left++, right--) {
        char swapper = text[left];
        text[left] = text[right];
        text[right] = swapper;
    }

    cout << "Reversed string: " << text;
    return 0;
}
