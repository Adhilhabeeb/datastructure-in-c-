// LINEAR SEARCH
#include<iostream>
using namespace std;
int main(){

    int a[10],data,i;
    int size;
    cout<<"Enter the size : ";
    cin>>size;
    cout<<"\nEnter the elements : "<<endl;
    for(i=0;i<size;i++){
        cin>>a[i];
    }

    cout<<"\nEnter the element for search : "<<endl;
    cin>>data;

    for(i=0;i<size;i++){
        if(a[i]==data){
            cout<<"\n The data "<<data<<" present in array";
            break;
        }
    }

    if(i==size){
        cout<<"\n The data not present"<<endl;
    }
    return 0;
}
