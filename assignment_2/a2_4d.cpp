#include <iostream>
using namespace std;

int main() {
    char text[20];
    cout << "Enter any string: ";
    cin >> text;

    int len = 0;
    while (text[len] != '\0') {
        len++;
    }

    for (int j= 0; j < len - 1; j++) {
        for (int i = 0; i < len - j - 1; i++) {
            if (text[i] > text[i + 1]) {
                char swapper = text[i];
                text[i] = text[i + 1];
                text[i + 1] = swapper;
