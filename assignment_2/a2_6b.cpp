#include <iostream>
using namespace std;

int** readSparse(int &rows, int &cols, int &nonZero) {
    cout << "Enter rows cols nonZero: ";
    cin >> rows >> cols >> nonZero;

    int **s = new int*[nonZero+1];
    for (int i=0; i<=nonZero; i++)
        s[i] = new int[3];

    s[0][0] = rows;
    s[0][1] = cols;
    s[0][2] = nonZero;

    cout << "Enter row col value for each nonZero element:\n";
    for (int i=1; i<=nonZero; i++) {
        cin >> s[i][0] >> s[i][1] >> s[i][2];
    }
    return s;
}

void printSparse(int **s) {
    int nonZero = s[0][2];
    for (int i=0; i<=nonZero; i++) {
        cout << s[i][0] << " " << s[i][1] << " " << s[i][2] << endl;
    }
}

int** addSparse(int **s1, int **s2, int &nonZero) {
    if (s1[0][0] != s2[0][0] || s1[0][1] != s2[0][1]) {
        cout << "Addition not possible\n";
        nonZero = 0;
        return nullptr;
    }

    int i=1, j=1, k=1;
    int maxSize = s1[0][2] + s2[0][2];
    int **sum = new int*[maxSize+1];
    for (int t=0; t<=maxSize; t++)
        sum[t] = new int[3];

    sum[0][0] = s1[0][0];
    sum[0][1] = s1[0][1];

    while (i <= s1[0][2] && j <= s2[0][2]) {
        if (s1[i][0] < s2[j][0] || (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1])) {
            sum[k][0] = s1[i][0];
            sum[k][1] = s1[i][1];
            sum[k][2] = s1[i][2];
            i++; k++;
        }
        else if (s2[j][0] < s1[i][0] || (s1[i][0] == s2[j][0] && s2[j][1] < s1[i][1])) {
            sum[k][0] = s2[j][0];
            sum[k][1] = s2[j][1];
            sum[k][2] = s2[j][2];
            j++; k++;
        }
        else {
            sum[k][0] = s1[i][0];
            sum[k][1] = s1[i][1];
            sum[k][2] = s1[i][2] + s2[j][2];
            i++; j++; k++;
        }
    }

    while (i <= s1[0][2]) {
        sum[k][0] = s1[i][0];
        sum[k][1] = s1[i][1];
        sum[k][2] = s1[i][2];
        i++; k++;
    }

    while (j <= s2[0][2]) {
        sum[k][0] = s2[j][0];
        sum[k][1] = s2[j][1];
        sum[k][2] = s2[j][2];
        j++; k++;
    }

    sum[0][2] = k - 1;
    nonZero = sum[0][2];
    return sum;
}

int main() {
    int rows, cols, s1, s2;
    cout << "Enter first sparse matrix:\n";
    int **s1 = readSparse(rows, cols, s1);

    cout << "Enter second sparse matrix:\n";
    int **s2 = readSparse(rows, cols, s2);

    cout << "\nSparse Matrix 1:\n"; printSparse(s1);
    cout << "\nSparse Matrix 2:\n"; printSparse(s2);

    int sum1;
    int **sum = addSparse(s1, s2, sum1);

    
        cout << "\nResultant Sparse Matrix:\n";
        printSparse(sum);
    }

    return 0;
}
