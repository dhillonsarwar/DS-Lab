#include<iostream>
using namespace std;
int * arrcreate(int n){
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }return arr;
    
}
int paircheck(int *arr,int n){
    int pair=0,k;
    cout<<"Enter the difference value: ";
    cin>>k;
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]-arr[j]==k){
                pair++;
                flag=true;
            }
        }
    }
    if(!flag){
        cout<<"No. of pairs found is ";return 0;
    }
    else{
        cout<<"No. of pairs found is ";
    return pair;}
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int *arr=arrcreate(n);
cout<<paircheck(arr,n)<<endl;
    
    return 0;
}
