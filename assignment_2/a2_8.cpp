#include<iostream>
using namespace std;
int noofduplicates(int* arr, int n) {
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
        }
    }
    return count;
}   
int main (){
    int arr[] = {1, 2, 2, 3, 4, 4, 5,6,6,7,8,9,9}; //sorted array with duplicates
    int n = sizeof(arr) / sizeof(arr[0]);
    int duplicates = 0;
    duplicates+=noofduplicates(arr, n);
    cout << "Number of unique elements in the array: " << n-duplicates << endl;
    return 0;
}