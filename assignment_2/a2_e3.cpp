#include <iostream>
#include<algorithm>
using namespace std;
bool ana=false;
void anacheck(string s,string r){ana=false;
    sort(s.begin(),s.end());
    sort(r.begin(),r.end());
    if(s==r){ana=true;
    
}}
int main() {int n;
cout<<"Enter number of test cases:";
cin>>n;
 cin.ignore();
for(int i=0;i<n;i++){
    string s1,s2;
    cout<<"Enter String 1 ";
   
    getline(cin,s1);
    cout<<"Enter String 2 ";
    getline(cin,s2);
    anacheck(s1,s2);
    if(ana){cout<<"YES"<<endl;}
    else {cout<<"NO"<<endl;}}
	

}
