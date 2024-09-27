#include<iostream>
using namespace std;

class TransposeM{
    int m1[20][20], m2[20][3], i, j, row, column, t;

public:
    void read(){
        t = 0;
        cout << "Enter the number of rows:\n";
        cin >> row;
        cout << "Enter the number of columns:\n";
        cin >> column;

        cout << "Enter the matrix elements (enter 0 for sparse elements):\n";
        for(i = 0; i < row; i++){
            for(j = 0; j < column; j++){
                cin >> m1[i][j];
                if(m1[i][j] != 0){  // if element is non-zero
                    t++;
                    // Store row, column, and value of non-zero elements
                    m2[t][0] = i;
                    m2[t][1] = j;
                    m2[t][2] = m1[i][j];
                }
            }
        }

        // Store matrix dimensions and total non-zero elements in the first row
        m2[0][0] = row;
        m2[0][1] = column;
        m2[0][2] = t;
    }

    void displaysp(){
        cout << "Sparse Matrix Representation (Row, Column, Value):\n";
        for(i = 0; i <= t; i++){  // <= because t stores the count of non-zero elements
            for(j = 0; j < 3; j++){
                cout << m2[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void transpose(){
        int transpose[20][3];

        // Initialize the transpose matrix's metadata (rows, columns, non-zero count)
        transpose[0][0] = m2[0][1]; // Transposed matrix has swapped dimensions
        transpose[0][1] = m2[0][0];
        transpose[0][2] = m2[0][2];

        int q = 1; // Transpose matrix starts from 1 (0 is metadata)

        // For each column in the original, find matching non-zero elements and transpose them
        for(i = 0; i < column; i++){
            for(int p = 1; p <= t; p++){
                if(m2[p][1] == i){  // If column matches
                    transpose[q][0] = m2[p][1]; // Swap row and column
                    transpose[q][1] = m2[p][0];
                    transpose[q][2] = m2[p][2];
                    q++;
                }
            }
        }

        // Display the transposed sparse matrix
        cout << "Transpose (Sparse Matrix Representation):\n";
        for(i = 0; i <= t; i++){
            for(j = 0; j < 3; j++){
                cout << transpose[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void display(){
        cout << "Original Matrix:\n";
        for(i = 0; i < row; i++){
            for(j = 0; j < column; j++){
                cout << m1[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main(){
    TransposeM obj;
    obj.read();        // Read the matrix and convert it to sparse form
    obj.display();     // Display the original matrix
    obj.displaysp();   // Display sparse matrix representation
    obj.transpose();   // Compute and display the transpose in sparse format

    return 0;
}
