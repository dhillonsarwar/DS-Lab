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

    for (int pass = 0; pass < len - 1; pass++) {
        for (int idx = 0; idx < len - pass - 1; idx++) {
            if (text[idx] > text[idx + 1]) {
                char swapper = text[idx];
                text[idx] = text[idx + 1];
                text[idx + 1] = swapper;
