// binary search
#include <iostream>
using namespace std;
int main()
{
    int a[10], n, i, j, temp;
    cout << "Enter the size of the array : " << endl;
    cin >> n;
    cout << "\n Enter the elements of the array : " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "\n Before Sorting : " << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "\n After Sorting : " << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }

    int min,max,mid,data;
    cout << "\n Enter the data to be searched : "<<endl;
    cin>>data;
    min=0;
    max=n-1;
    mid=(min+max)/2;
    while(min<=max){
        if(a[mid]==data){
            cout<<"\n The searched data "<<data<<" presented in array at "<<mid+1<<"\n";
            break;
        }else if(a[mid]<data){
            min=mid+1;
        }else{
            max=mid-1;
        }

        mid=(max+min)/2;
    }

    if(min>max){
        cout<<"Not found "<<data<<" in array\n";
    }

    return 0;
}
