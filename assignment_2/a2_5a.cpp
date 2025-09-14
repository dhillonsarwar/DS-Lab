#include<iostream>
using namespace std;
int* getArray(int size) {
    int* arr = new int[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin>>arr[i];
    }
    return arr;
}
int main (){
    cout<<"Enter the order of matrix: ";
    int n;
    cin>>n;
    int* arr = getArray(n);
    for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
           if(i==j) {
               cout << arr[i] << " ";
           } else {
               cout << "0 ";
           }
        }
        cout << endl;
    }}
