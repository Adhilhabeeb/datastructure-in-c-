
#include<iostream>
using namespace std;
int main(){
    int a[10];
    int size,i,pos,data;
    cout<<"\nEnter the size:\n";
    cin>>size;
    cout<<"\nEnter the array elements:\n";
    for(i=0;i<=size;i++){
         cin>>a[i];
    }
    cout<<"\n before insertion\n";
    for(i=0;i<=size;i++){
         cout<<a[i]<<"\t";
    }
    cout<<"\nEnter the data to be inserted:\n";
    cin>>data;
    cout<<"\nEnter the position of data(index):\n";
    cin>>pos; 
    for(i=size-1;i>=pos;i--){
        a[i+1]=a[i];
    }
    a[pos]=data;
    cout<<"\n after insertion\n";
    for(i=0;i<size;i++){
        cout<<a[i]<<"\t";
    }
    return 0;
}
