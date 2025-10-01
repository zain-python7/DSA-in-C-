#include <iostream>
using namespace std;
int main() {
    int r;

    
    cout << "enter the total number of students : "<<endl;
    cin >> r ;
    int **arr=new int *[r];
    int *c=new int[r];
    for(int i=0;i<r;i++){
        cout<<"enter the number of subjects student "<<i+1<<" is envolved"<<":";
        cin>>c[i];
        arr[i]=new int[c[i]];
    }

    for (int i=0;i<r;i++){
        
        for(int j=0;j<c[i];j++){
            cout<<"enter the numbr of student no "<<i+1<<" for subject "<<j+1<<":";
            cin>>arr[i][j];
        }
    }
    int count=0;
    for (int i=0;i<r;i++){
        cout<<"the number student "<<i+1<<" got"<<":";
        for(int j=0;j<c[i];j++){
            cout<<arr[i][j]<<" ";
           
            count+=arr[i][j];
        }

        cout<<"average number of subject is :"<<(count/c[i])<<endl;
        count=0;
        
    }

    
    
   

    
    for (int i = 0; i < r; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
