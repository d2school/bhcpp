#include <iostream>

using namespace std;

int from_share_lib (int n1, int n2)
{
    cout << __func__  << endl;

    int r = n1 + n2;

    return r;
}
