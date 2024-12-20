/*
Q21:
            Write a program to implement Symmetric Matrix using one-dimensional array.
Code:
*/
#include <iostream>
using namespace std;

/* Symmetric Matrix Class */
class SymmetricMatrix
{
    int *arr;
    int size;
    public:
    SymmetricMatrix(int x)
    {
        this->size = x;
        arr = new int[size];
    }
    ~SymmetricMatrix()
    {
        delete[] arr;
    }

    /* To store an element 'n' at index (x, y): (input as 1-indexing) */
    void store(int x, int y, int n)
    {
        if (x < 1 || x > size || y < 1 || y > size)
        {
            cerr << "Err: Index out of bound.";
            exit(1);
        }
        if (x <= y)
    {
      int k = (y*(y-1)/2 + (x-1));
      arr[k] = n;
    }
    }

    /* To retrive element at index (x, y): (input as 1-indexing) */
    int retrieve(int x, int y)
    {
        if (x < 1 || x > size || y < 1 || y > size)
        {
            cerr << "Err: Index out of bound.";
            exit(1);
            return -1;
        }
        else if (x <= y)
        {
      int k = (y*(y-1)/2 + (x-1));
      return arr[k];
    }
        else if (x > y)
        {
      int k = (x*(x-1)/2 + (y-1));
      return arr[k];
    }
        return 0;
    }

    /* To show all the elements of matrix */
    void show()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << "\n\t";
            for (int j = 0; j < size; ++j)
            {
                cout << retrieve(i+1, j+1) << "  ";
            }
        }
        cout << endl;
    }
};

int main()
{
    cout << "\n\t ~~~~~~~~~~~~~~~~~~~~~~~Practical 21~~~~~~~~~~~~~~~~~~~~\n\t\t\t\t  \n";
    int x, y;

    /* Take input and store */
    cout << "\nEnter the no. of rows: ";
    cin >> x;
    cout << "Enter the no. of columns: ";
    cin>>y;
    if (x != y)
    {
        cerr << "Err: No. of rows and columns must be same.";
        exit(1);
    }

    SymmetricMatrix sym(x);
    cout << "Enter the matrix elements (by row):\n";
    for (int i = 1; i <= x; ++i)
    {
        int n;
    for (int j = i; j <= x; ++j)
    {
      cin >> n;
            sym.store(i, j, n);
    }
    }

    /* Show matrix */
    cout << "\nResultant Symmetric Matrix:\n";
    sym.show();


  return 0;
}
