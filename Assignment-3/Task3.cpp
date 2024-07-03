#include <iostream>
using namespace std;

template <class T>
class Matrix
{
protected:
    int x, y;
    T **mat;

public:
    Matrix(int x, int y) : x(x), y(y)
    {
        mat = new T *[x];
        for (int i = 0; i < x; i++)
        {
            mat[i] = new T[y];
        }
    }

    Matrix() : x(0), y(0), mat(nullptr) {}

    void setElement(int i, int j, T value)
    {
        if (i >= 0 && i < x && j >= 0 && j < y)
        {
            mat[i][j] = value;
        }
        else
        {
            cout << "Index out of bounds" << endl;
        }
    }
    T getElement(int i, int j) const
    {
        if (i >= 0 && i < x && j >= 0 && j < y)
        {
            return mat[i][j];
        }
        else
        {
            cout << "array out of bounds" << endl;
            return 0;
        }
    }
    int getRows() { return this->x; }
    int getCols() { return this->y; }

    Matrix<T> &operator+(Matrix<T> &obj)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                this->mat[i][j] += obj.getElement(i, j);
            }
        }
        return *this;
    }

    Matrix<T> &operator-(Matrix<T> &obj)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                this->mat[i][j] -= obj.getElement(i, j);
            }
        }
        return *this;
    }

    Matrix<T> &operator*(Matrix<T> &obj)
    {
        if (this->y != obj.getRows())
        {
            throw std::invalid_argument("Matrix dimensions mismatch for multiplication");
        }

        // Temporary matrix with dimensions this->x by obj.getCols()
        T **temp = new T *[this->x];
        for (int i = 0; i < this->x; i++)
        {
            temp[i] = new T[obj.getCols()];
            std::fill(temp[i], temp[i] + obj.getCols(), 0); // Initialize to zero
        }

        // Performing matrix multiplication
        for (int i = 0; i < this->x; i++)
        {
            for (int j = 0; j < obj.getCols(); j++)
            {
                for (int k = 0; k < this->y; k++)
                {
                    temp[i][j] += this->mat[i][k] * obj.getElement(k, j);
                }
            }
        }

        // Replace the old mat with the new mat of potentially different size
        for (int i = 0; i < this->x; i++)
        {
            delete[] this->mat[i];
        }
        delete[] this->mat;

        this->mat = temp;
        this->y = obj.getCols(); // New number of columns

        return *this;
    }
    virtual void printMatrix() const = 0;
};

class IntMatrix : public Matrix<int>
{
public:
    IntMatrix(int x, int y, int initial = 0) : Matrix<int>(x, y)
    {
        for (int i = 0; i < x; ++i)
            for (int j = 0; j < y; ++j)
                mat[i][j] = initial;
    }

    Matrix<int> &operator=(Matrix<int> &obj)
    {
        for (int i = 0; i < this->x; i++)
        {
            for (int j = 0; j < this->y; j++)
            {
                this->mat[i][j] = obj.getElement(i, j);
            }
        }
        return *this;
    }

    void printMatrix() const override
    {
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class DoubleMatrix : public Matrix<double>
{
public:
    DoubleMatrix(int rows, int cols, double initial = 0.0) : Matrix<double>(rows, cols)
    {
        for (int i = 0; i < x; ++i)
            for (int j = 0; j < y; ++j)
                mat[i][j] = initial;
    }
    Matrix<double> &operator=(Matrix<double> &obj)
    {
        for (int i = 0; i < this->x; i++)
        {
            for (int j = 0; j < this->y; j++)
            {
                this->mat[i][j] = obj.getElement(i, j);
            }
        }
        return *this;
    }

    void printMatrix() const override
    {
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};
void solveForIntegerMat()
{
    IntMatrix m1(2, 2); // Create an instance of
    m1.setElement(0, 0, 1);
    m1.setElement(0, 1, 2);
    m1.setElement(1, 0, 3);
    m1.setElement(1, 1, 4);
    cout << "The first Matrix:" << endl;
    cout << "--------------------------" << endl;
    m1.printMatrix();
    cout << "--------------------------" << endl
         << endl;

    IntMatrix m2(2, 2);
    m2.setElement(0, 0, 5);
    m2.setElement(0, 1, 6);
    m2.setElement(1, 0, 7);
    m2.setElement(1, 1, 8);

    cout << "The second Matrix:" << endl;
    cout << "--------------------------" << endl;
    m2.printMatrix();
    cout << "--------------------------" << endl
         << endl;

    IntMatrix m3(2, 2);
    m3.setElement(0, 0, 1);
    m3.setElement(0, 1, 2);
    m3.setElement(1, 0, 3);
    m3.setElement(1, 1, 4);

    IntMatrix m4(2, 2);
    m4.setElement(0, 0, 5);
    m4.setElement(0, 1, 6);
    m4.setElement(1, 0, 7);
    m4.setElement(1, 1, 8);

    IntMatrix m5(2, 2);
    m5.setElement(0, 0, 1);
    m5.setElement(0, 1, 2);
    m5.setElement(1, 0, 3);
    m5.setElement(1, 1, 4);

    IntMatrix m6(2, 2);
    m6.setElement(0, 0, 5);
    m6.setElement(0, 1, 6);
    m6.setElement(1, 0, 7);
    m6.setElement(1, 1, 8);

    IntMatrix m7(2, 2);
    m7 = m1 - m2; // Difference
    cout << "The difference of these two matrices is:" << endl;
    m7.printMatrix();
    cout << "--------------------------" << endl;

    IntMatrix m8(2, 2);
    m8 = m3 + m4; // Sum
    cout << "The sum of these two matrices is:" << endl;
    cout << "--------------------------" << endl;
    m8.printMatrix();
    cout << "--------------------------" << endl;

    IntMatrix m9(2, 2);
    m9 = m5 * m6; // Product
    cout << "The product of these two matrices is:" << endl;
    m9.printMatrix();
    cout << "--------------------------" << endl;
}
void solveForDoubleMat()
{
    DoubleMatrix m1(2, 2); // Create an instance of
    m1.setElement(0, 0, 1.1);
    m1.setElement(0, 1, 2.2);
    m1.setElement(1, 0, 3.3);
    m1.setElement(1, 1, 4.4);
    cout << "The first Matrix:" << endl;
    cout << "--------------------------" << endl;
    m1.printMatrix();
    cout << "--------------------------" << endl
         << endl;

    DoubleMatrix m2(2, 2);
    m2.setElement(0, 0, 5.5);
    m2.setElement(0, 1, 6.6);
    m2.setElement(1, 0, 7.7);
    m2.setElement(1, 1, 8.8);

    cout << "The second Matrix:" << endl;
    cout << "--------------------------" << endl;
    m2.printMatrix();
    cout << "--------------------------" << endl
         << endl;

    DoubleMatrix m3(2, 2);
    m3.setElement(0, 0, 1.1);
    m3.setElement(0, 1, 2.2);
    m3.setElement(1, 0, 3.3);
    m3.setElement(1, 1, 4.4);

    DoubleMatrix m4(2, 2);
    m4.setElement(0, 0, 5.5);
    m4.setElement(0, 1, 6.6);
    m4.setElement(1, 0, 7.7);
    m4.setElement(1, 1, 8.8);

    DoubleMatrix m5(2, 2);
    m5.setElement(0, 0, 1.1);
    m5.setElement(0, 1, 2.2);
    m5.setElement(1, 0, 3.3);
    m5.setElement(1, 1, 4.4);

    DoubleMatrix m6(2, 2);
    m6.setElement(0, 0, 5.5);
    m6.setElement(0, 1, 6.6);
    m6.setElement(1, 0, 7.7);
    m6.setElement(1, 1, 8.8);

    DoubleMatrix m7(2, 2);
    m7 = m1 - m2; // Difference
    cout << "The difference of these two matrices is:" << endl;
    m7.printMatrix();
    cout << "--------------------------" << endl;

    DoubleMatrix m8(2, 2);
    m8 = m3 + m4; // Sum
    cout << "The sum of these two matrices is:" << endl;
    cout << "--------------------------" << endl;
    m8.printMatrix();
    cout << "--------------------------" << endl;

    DoubleMatrix m9(2, 2);
    m9 = m5 * m6; // Product
    cout << "The product of these two matrices is:" << endl;
    m9.printMatrix();
    cout << "--------------------------" << endl;
}
int main()
{
    int choice;
    cout << "1. solve for integer matrix" << endl;
    cout << "2. solve for integer matrix" << endl;
    while (1)
    {
        cout << "Enter Choice:";
        cin >> choice;
        if (choice == 1)
        {
            solveForIntegerMat();
        }
        else if (choice == 2)
        {
            solveForDoubleMat();
        }
        else
        {
            cout << "invalid choice, try again" << endl;
            continue;
        }
    }
}