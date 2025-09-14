#include<iostream>
using namespace std;
int* getArray(int size) {
    int* arr = new int[size];
    cout << "Enter " << size*(size+1)/2 << " elements: ";
    for (int i = 0; i < size*(size+1)/2; i++) {
        cin>>arr[i];
    }
    return arr;
}
int main (){
    int k = 0,l=0;
    cout<<"Enter the order of matrix: ";
    int n;
    cin>>n;
    int* arr = getArray(n);
    cout << "The Symmetric triangular matrix is:" << endl;
    for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
           if(i>=j) {
               cout << arr[k++] << " ";
           } else {
               
               cout << arr[j*(j+1)/2+i] << " ";
               }
           }
        
        cout << endl;
    }}
