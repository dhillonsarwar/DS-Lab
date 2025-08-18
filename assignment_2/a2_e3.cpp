#include <iostream>
using namespace std;

int main()
{
    char str1[20], str2[20];
    int hash[26] = {0};
    cout << "Enter string 1: ";
    cin >> str1;
    cout << "Enter string 2: ";
    cin >> str2;

    int n1 = 0, n2 = 0;

    for (int i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; j++, i++)
    {
        hash[str1[i] - 'a']++;
        hash[str2[i] - 'a']--;
        n1++;
        n2++;
    }

    bool flag = true;

    if (n1 == n2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (hash[i] != 0)
            {
                flag = false;
                break;
            }
        }
    }

    else
    {
        cout << "Not anagram";
        return 0;
    }
    if (flag)
    {
        cout << "Anagram";
    }
    else
    {
        cout << "not anagram";
    }

    return 0;
}
