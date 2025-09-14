#include<iostream>
using namespace std;
int ** sparse(int m,int n,int v){
    int** a=new int* [v+1];
    for(int i=0;i<=v;i++){
        a[i]=new int[3];
    }
    a[0][0]=m;
    a[0][1]=n;      
    a[0][2]=v;
    for(int i=1;i<=v;i++){
        cout<<"enter row no., column no. and value";
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    return a;
}


int** multiply(int** A, int** B) {
    if (A[0][1] != B[0][0]) {
        cout << "Multiplication not possible!" << endl;
        return nullptr;
    }

    int maxSize = A[0][2] * B[0][2] + 1;
    int** m = new int*[];
    for (int i = 0; i < maxSize; i++) m[i] = new int[3];

    m[0][0] = A[0][0];
    m[0][1] = B[0][1];
    m[0][2] = 0;

    int k = 1;

    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= B[0][2]; j++) {
            if (A[i][1] == B[j][0]) {
                int row = A[i][0];
                int col = B[j][1];
                int val = A[i][2] * B[j][2];

                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (m[x][0] == row && m[x][1] == col) {
                        m[x][2] += val;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    m[k][0] = row;
                    m[k][1] = col;
                    m[k][2] = val;
                    k++;
                }
            }
        }
    }

    m[0][2] = k - 1;  delete []m;
    return m;

}

void sparsetomarix(int** a){
    int m=a[0][0];
    int n=a[0][1];
    int v=a[0][2];
    int k=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(k<=v && a[k][0]==i && a[k][1]==j){
                cout<<a[k][2]<<" ";
                k++;
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}



int main (){
    int m,n,v;
    cout<<"enter no. of rows, columns and non-zero values";
    cin>>m>>n>>v;
    int** a=sparse(m,n,v);
  cout<<"enter no. of rows, columns and non-zero values";
    cin>>m>>n>>v;
int **b=sparse(m,n,v);
  int **c=multiply(a,b);
  sparsetomatrix(c);
 delete[]a,b,c;
  return 0; 
}
  
  
    
            

}
