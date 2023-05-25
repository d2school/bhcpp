#include <ctime>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    clock_t beg = clock();

    for (int i=0; i<30000; ++i)
    {
        cout << "hello world.";
    }


    clock_t end = clock();
    cout << "\n" << (end - beg) * 1000 / CLOCKS_PER_SEC << "ms." <<endl; //�� CLOCKS_PER_SEC : ÿ���а������ٸ� clock


    return 0;
}
