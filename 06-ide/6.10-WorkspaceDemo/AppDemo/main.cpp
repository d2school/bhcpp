#include <iostream>

using namespace std;

extern int from_share_lib (int n1, int n2);
extern double from_static_lib (int n1, int n2);

int main()
{
    int n1,n2;

    cout << "please input n1, n2 : ";

    cin >> n1 >> n2;

    int tmp = from_share_lib(n1, n2);
    double result = from_static_lib(n1, tmp);

    cout << "result is " << result << endl;

    return 0;
}
