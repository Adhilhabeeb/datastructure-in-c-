// QUICK SORT
#include <iostream>
using namespace std;
void quicksort(int a[], int lb, int ub);
int partition(int a[], int lb, int ub);
int main()
{
    int a[20], lb, ub;
    int i, n;
    cout << "Enter the size of the array : \n";
    cin >> n;
    lb = 0;
    ub = n - 1;
    cout << "Enter the elements of the array :\n";
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout << "Before sorting :\n";
    for (i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }

    quicksort(a,lb,ub);
    cout << "\nAfter sorting :\n";
    for (i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }

    return 0;
}

void quicksort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc;
        loc = partition(a, lb, ub);
        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
    }
}

int partition(int a[], int lb, int ub)
{
    int pivot;
    pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start <= end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }

        while (a[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            int temp;
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }

    int temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}
