#include <iostream>
using namespace std;

int main() {
    char text[20];
    cout << "Enter any string: ";
    cin >> text;

    for (int k = 0; text[k] != '\0'; k++) {
        if (text[k] == 'a' || text[k] == 'e' || text[k] == 'i' || text[k] == 'o' || text[k] == 'u' ||
            text[k] == 'A' || text[k] == 'E' || text[k] == 'I' || text[k] == 'O' || text[k] == 'U') {

            for (int m = k; text[m] != '\0'; m++) {
                text[m] = text[m + 1];
            }
            k--; 
        }
    }

    cout << "After removing vowels: " << text;
    return 0;
}
