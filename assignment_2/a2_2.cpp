#include <iostream>
using namespace std;

void bubbleSort(int* arr, int n) {
    bool swap; int temp;
    
    for (int i = 0; i< n - 1; i++) {
        swap = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
              
                swap = true;
            }
        }
     
        if (!swap)
            break;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22,11,90};
    int x=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,x);
    cout<<"Sorted Array is :";
    for(int i=0;i<x;i++){
        cout<<arr[i]<<"  ";
    }}