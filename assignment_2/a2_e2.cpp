#include <iostream>
#include <string>
#include <vector>
using namespace std;

string canSplit(string s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
        if (freq[c - 'a'] >= 2)
            return "YES";
    }
    return "NO";
}

int main() {
    string s;
    cin >> s;
    cout << canSplit(s) << endl;
    return 0;
}
