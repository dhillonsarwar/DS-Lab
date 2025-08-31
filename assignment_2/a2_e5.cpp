#include<iostream>
using namespace std;
void zeroadder(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            for(int j = n - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            arr[i + 1] = 0;
            i++; }
    }
}
void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] < 0||arr[i] > 9) {
            cout << "Invalid Input"<<endl<<"Enter again"<<endl;
            i--;
        
        }
    }
    display(arr, n);
    zeroadder(arr, n);
    display(arr, n);
    delete[] arr;
    return 0;
}
