#include "Matrix.h"
#include <iostream>
using namespace std;


int main()
{
    int n = 2, m = 2;
    Matrix<int> arr1(n, m);
    arr1.fill();
    cout << arr1[0][0];
    return 0;
}
