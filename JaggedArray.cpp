#include <iostream>
using namespace std;
int main() {
    int r;

    
    cout << "enter the number of rows : "<<endl;
    cin >> r ;
    int **arr=new int *[r];
    int *c=new int[r];
    for(int i=0;i<r;i++){
        cout<<"enter the number of coulms for row "<<i+1<<":";
        cin>>c[i];
        arr[i]=new int[c[i]];
    }

    for (int i=0;i<r;i++){
        cout<<"enter the numbr of elemnets of row "<<i+1<<":";
        for(int j=0;j<c[i];j++){
            cin>>arr[i][j];
        }
    }
    for (int i=0;i<r;i++){
        cout<<endl;
        for(int j=0;j<c[i];j++){
            cout<<arr[i][j]<<" ";
        }
    }

    
    
   

    
    for (int i = 0; i < r; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
