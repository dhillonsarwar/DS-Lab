#include<iostream>
using namespace std;
int search (int* arr,int val,int x){
    
    int left=0,right=x-1,mid;
    while(left<=right){mid=left+(right-left)/2;
        if (arr[mid]==val){
            return mid;
        }
        if(val<arr[mid]){
            right=mid-1;
        }
        else{left=mid+1;
    }
}return -1;}
int main (){
    int arr[] ={1,2,3,4,5};
   int x=sizeof(arr)/sizeof(arr[0]);
   int val;
   cout<<"Enter the element that you want to search for :"
   ;cin>>val;
    
    if(search(arr,val,x)!=-1) {
        cout << "Found at  " << search(arr, val, x);
    } 
    else {
        cout << " Not Found";
    }
}