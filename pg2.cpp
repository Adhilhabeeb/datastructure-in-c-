// merge array
#include<iostream>
using namespace std;

int main() {
int arr1[10], arr2[10], arr3[20], size1, size2, size3, i, j, k;

cout << "\n enter the size of first array : ";
cin >> size1;

cout << "\n enter the size of second array : ";
cin >> size2;

cout << "\n enter the element of first array : \n";
for(i = 0; i < size1; i++) {
    cin >> arr1[i];
}

cout << "\n enter the element of second array : \n";
for(i = 0; i < size2; i++) {
    cin >> arr2[i];
}

for(i = 0; i < size1; i++) {
    arr3[i] = arr1[i];
}

size3 = size1 + size2;

for(i = 0, k = size1;i < size2 && k < size3; i++, k++) {
    arr3[k] = arr2[i];
}

cout << "\n new array after merging is ";
for(i = 0; i < size3; i++) {
    cout << arr3[i] << "\t";
}

return 0;
}