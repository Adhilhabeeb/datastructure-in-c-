// SPARSE MATRIX IN TRIPLET FORM
#include <iostream>
using namespace std;
class Sparse
{
    int a[10][10], b[10][10];

public:
    int n, m;
    void read();
    void display();
    void convert();
    void sparseDisplay();
};

void Sparse::read()
{
    int i, j;
    cout << "Enter the number of rows and columns of matrix A" << endl;
    cin >> m >> n;
    cout << "\n Enter the elements of matrix : " << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void Sparse::display()
{
    int i, j;
    cout << "\n Matrix is \n"
         << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
    cout<<"------------"<<endl;
}

void Sparse::convert(){
    int i,j,k=1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i][j]!=0){
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    k=k-1;
    b[0][0]=m;
    b[0][1]=n;
    b[0][2]=k;
}

void Sparse::sparseDisplay(){
    int i,j;
    int k=b[0][2];

    for(i=0;i<k+1;i++){
        for(j=0;j<3;j++){
            cout<<b[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"------------"<<endl;
}

int main(){
    Sparse p;
    p.read();
    cout<<"\n The Array is ";
    p.display();
    p.convert();
    p.sparseDisplay();
    return 0;
}
