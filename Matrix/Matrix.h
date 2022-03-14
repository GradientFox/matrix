#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct Matrix
{
private:
    const int width;
    const int height;
    T** data;
public:
    Matrix(int _width, int _height) :width(_width), height(_height) {
        data = new T* [height];
        for (int row = 0; row < height; row++)
        {
            data[row] = new T[width];
        }
    }
    Matrix(const Matrix& other) : width(other.width), height(other.height)
    {
        data = new T* [height];
        for (int row = 0; row < height; row++)
        {
            int* temp = new T[width];
            for (int col = 0; col < width; col++)
            {
                temp[col] = other.data[row][col];
            }
            data[row] = temp;
        }
    }
    ~Matrix() {
        for (int row = 0; row < this->height; row++)
        {
            delete[] data[row];
        }
        delete[] data;
        //cout << "Matrix is deleted successfully" << endl;
    }
    void fill()
    {
        
        cout << "Enter matrix with size: " << this->height << "x" << this->width << ". Delimiter - space.\n";
        for (int irow = 0; irow < this->height; irow++)
        {
            for (int icol = 0; icol < this->width; icol++)
            {
                int x;
                cin >> x;
                this->get(irow, icol) = x;
            }
        }
        cout << "Matrix filled.\n";
    }
    void print() {
        cout << '[';
        for (int y = 0; y < height; y++) {
            if (y != 0)
                cout << ' ';
            cout << "[";
            for (int x = 0; x < width; x++) {
                if (x > 0)
                    cout << ", ";
                cout << data[y][x];
            }
            if (y == height - 1)
                cout << ']';
            else
                cout << "]," << endl;
        }
        cout << "]" << endl;
    }
    T** getMatrix()
    {
        return this->data;
    }
    const int getWidth()
    {
        return this->width;
    }
    const int getHeight()
    {
        return this->height;
    }
    T& get(int row, int col)
    {
        return this->data[row][col];
    }
    T* operator [](int a)
    {
        return this->data[a];
    }
    Matrix<T> operator+(Matrix<T> other) {
        Matrix<T> newMatrix(this->getWidth(), this->getHeight());
        for (int irow = 0; irow < newMatrix.getHeight(); irow++)
        {
            for (int icol = 0; icol < newMatrix.getWidth(); icol++)
            {
                newMatrix.get(irow, icol) = this->get(irow, icol) + other.get(irow, icol);
            }
        }
        return newMatrix;
    }
    Matrix<T> operator*(Matrix<T> other)
    {
        Matrix<T> newMatrix(other.getWidth(), this->getHeight());
        for (int row = 0; row < this->getHeight(); row++)
        {
            int* tmp = new int[other.getWidth()];
            for (int col = 0; col < other.getWidth(); col++)
            {
                int C = 0;
                for (int k = 0; k < this->getWidth(); k++)
                {
                    C += this->get(row,k) * other.get(k, col);
                }
                newMatrix.get(row, col) = C;
            }
        }
        return newMatrix;
    }
    void operator ++(int) // Прибавление единичнйо мтарицы
    {
        Matrix<T> newMatrix(this->getWidth(), this->getHeight());
        for (int irow = 0; irow < newMatrix.getHeight(); irow++)
        {
            for (int icol = 0; icol < newMatrix.getWidth(); icol++)
            {
                if (icol == irow)
                {
                    newMatrix.get(irow, icol) = 1;
                }
                else
                {
                    newMatrix.get(irow, icol) = 0;
                }
            }
        }
        for (int irow = 0; irow < this->getHeight(); irow++)
        {
            for (int icol = 0; icol < this->getWidth(); icol++)
            {
                this->get(irow, icol) = this->get(irow, icol) + newMatrix.get(irow, icol);
            }
        }
    }
    void operator --(int) // Вычитаем единичную матрицу
    {
        Matrix<T> newMatrix(this->getWidth(), this->getHeight());
        for (int irow = 0; irow < newMatrix.getHeight(); irow++)
        {
            for (int icol = 0; icol < newMatrix.getWidth(); icol++)
            {
                if (icol == irow)
                {
                    newMatrix.get(irow, icol) = 1;
                }
                else
                {
                    newMatrix.get(irow, icol) = 0;
                }
            }
        }
        for (int irow = 0; irow < this->getHeight(); irow++)
        {
            for (int icol = 0; icol < this->getWidth(); icol++)
            {
                this->get(irow, icol) = this->get(irow, icol) - newMatrix.get(irow, icol);
            }
        }
    }
};