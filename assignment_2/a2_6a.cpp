#include<iostream>
using namespace std;
int* arr;
int* sparmatrix(int m,int n,int k){
    int arr[k+1][3]; // Array to store sparse matrix
    arr[0][0] = m; // Store number of rows
    arr[0][1] = n; // Store number of columns
    arr[0][2] = k; // Store number of non-zero elements
    cout<<"Enter the non-zero elements in the format (row column value):"<<endl;
    for(int i = 1; i <=k; i++) {
        int row, col, value;
      
        cin >> row >> col >> value;
          if(row < 0 || row >= m || col < 0 || col >= n) {
            cout << "Invalid input. Please enter valid row and column indices." << endl;
            i--; // Decrement i to repeat the input for this index
            continue;
        }
        arr[i][0] = row;
        arr[i][1] = col;
        arr[i][2] = value;
    }
    cout << "The Sparse Matrix is:" << endl;
    for(int i = 0; i <= k; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;   
    }
    return &arr[0][0]; // Return pointer to the first element of the array
    
}
int main () {
    cout<<"Enter Number of Rows: ";
    int m;
    cin>>m;
    cout<<"Enter Number of Columns: ";
    int n;
    cin>>n;
    cout<<"Enter the number of non-zero elements: ";
    int k;
    cin>>k;
    int transposed[k+1][3]; // Array to store transposed sparse matrix
int* matr= sparmatrix(m,n,k);
    cout << "Sparse matrix stored successfully." << endl;
    int rows = matr[0][0]; int cols = matr[0][1]; int nonZero = matr[0][2];
transposed[0][0] = cols; transposed[0][1] = rows; transposed[0][2] = nonZero;
int l = 1;
for (int i = 0; i < cols; i++) {
for (int j = 1; j <= nonZero; j++) {
if (matr[j][1] == i) {
transposed[k][0] = matr[j][1];
transposed[k][1] = matr[j][0];
transposed[k][2] = matr[j][2];
l++;
} } } 
    
    return 0;
}
