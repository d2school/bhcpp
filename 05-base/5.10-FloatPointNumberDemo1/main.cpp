#include <iostream>

using namespace std;

int main()
{
    if (1.0 / 2.0 == 0.5f)
    {
        cout << "yes!" << endl;
    }
    else
    {
        cout << "NO~~~" << endl;
    }
    
    if (0.01f * 10.0f / 0.2f == 0.5f)
    {
        cout << "yes!" << endl;
    }
    else
    {
        cout << "no." << endl;
    }
    
    float f = 0.5f;

    cout << "sizeof float = " << sizeof(float) << "=" << sizeof(f) << endl;
    cout << f << endl;

    return 0;
}
