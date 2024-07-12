// selection sort
#include <iostream>
using namespace std;
int main()
{
    int a[10], i, min, n, j, temp;
    cout << "\n Enter the size of array : ";
    cin >> n;
    cout << "\n Enter the elements of array : \n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "\n Before sorting is \n";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }

    // sorting
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    cout << "\n After sorting is \n";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    return 0;
}
