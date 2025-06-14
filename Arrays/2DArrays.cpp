#include <iostream>
using namespace std;

void printSpiral(int matrix[][4], int n, int m)
{
    int srow = 0, scol = 0;
    int erow = n - 1, ecol = m - 1;
    while (srow <= erow && scol <= ecol)
    {
        // top row
        for (int j = scol; j <= ecol; j++)
        {
            cout << matrix[srow][j] << " ";
        }

        // right column
        for (int i = srow + 1; i <= erow; i++)
        {
            cout << matrix[i][ecol] << " ";
        }

        // bottom row
        if (erow > srow)
        {
            for (int j = ecol - 1; j >= scol; j--)
            {
                cout << matrix[erow][j] << " ";
            }
        }

        // left column
        if (ecol > scol)
        {
            for (int i = erow - 1; i > srow; i--)
            {
                cout << matrix[i][scol] << " ";
            }
        }

        srow++;
        scol++;
        erow--;
        ecol--;
    }
}

bool search(int mat[][4], int n, int m, int key)
{
    // matrix is sorted row wise and column wise also called staircase matrix

    int i = 0, j = m - 1;

    while (i < n && j >= 0)
    {
        if (mat[i][j] == key)
        {
            cout << "Found at (" << i << ", " << j << ")" << endl;
            return true;
        }
        else if (mat[i][j] > key)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    cout << "Not found" << endl;
    return false;
}

void diagonalSum(int mat[][4], int n)
{
    int sum = 0;

    // O(n^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum += mat[i][j];
            }
            else if (i + j == n - 1)
            {
                sum += mat[i][j];
            }
        }
    }
    cout << "O(N^2) code => sum = " << sum << endl;

    // O(n)
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i];
        if (n - 1 - i != i)
            sum += mat[i][n - 1 - i];
    }
    cout << "O(N) code => sum = " << sum << endl;
}

int main()
{
    int matrix[4][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};

    int matrix2[3][4] = {{1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {9, 10, 11, 12}};

    // printSpiral(matrix, 4, 4);
    // Expected : 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

    // printSpiral(matrix2, 3, 4);

    // diagonalSum(matrix, 4);

    int mat[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};

    search(mat, 4, 4, 33);
    search(mat, 4, 4, 100);

    // Pointers & 2D Arrays
    //  func(matrix);
    return 0;
}