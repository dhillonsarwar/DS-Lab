#include<iostream>
using namespace std;
bool found=false;
void linearSearch(int* arr, int n, int val) {
    for (int i = 0; i < n; i++) {found = false;
        if (arr[i] == val) {
            found=true;
            return;
        }
    }
    
    
}
int main (){
    int arr[] = {1, 2, 3, 5};
    int x = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i <= x; i++) {
        linearSearch(arr, x, i);
        if (!found) {
            cout << "Element " << i << " not found in the array." << endl;
        break;}
    }
    
    if(found)cout<<"all elements are there";
    return 0;
}

