#include<iostream>
using namespace std;
int* getArray(int size) {
    int* arr = new int[size];
    cout << "Enter " << 3*size-2 << " elements: ";
    for (int i = 0; i < 3*size-2 ; i++) {
        cin>>arr[i];
    }
    return arr;
}
int main (){
    int k = 0;
    cout<<"Enter the order of matrix: ";
    int n;
    cin>>n;
    int* arr = getArray(n);
    for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
        
           if(((i-j)==1)||((j-i)==1)||(i==j)) { 
           while(k<3*n-2) {
               cout << arr[k] << " ";
               k++;
               break;
           }}
            else {
               cout << "0 ";
           }}
        
        cout << endl;
    }}
