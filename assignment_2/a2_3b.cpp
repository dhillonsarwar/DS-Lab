#include<iostream>
using namespace std;
bool found=false;
void search (int* arr,int x,int val){
    found = false;
    int left=0,right=x-1,mid;
    while(left<=right){mid=left+(right-left)/2;
        if (arr[mid]==val){
            found=true;
        }
        if(val<arr[mid]){
            right=mid-1;
        }
        else{left=mid+1;
    }
}}
int main (){
    int arr[] = {1, 2, 3, 5}; //sorted
    int x = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i <= x; i++) {
        search(arr, x, i);
        if (!found) {
            cout << "Element " << i << " not found in the array." << endl;
        break;}
    }
    
    if(found)cout<<"all elements are there";
    return 0;
}

