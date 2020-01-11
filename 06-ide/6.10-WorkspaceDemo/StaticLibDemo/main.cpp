#include <iostream>

using namespace std;

double from_static_lib (int n1, int n2)
{
    cout << __func__ << endl;

    int r = n1 / n2;

    return r;
}

