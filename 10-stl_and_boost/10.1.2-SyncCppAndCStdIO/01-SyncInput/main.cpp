#include <cstdio> // C 语言的标准输入输出库
#include <iostream>

using namespace std;

int main()
{
    // 可用于对比： 同步，或不同步：
    ios_base::sync_with_stdio(false); // 不同步！！！

    int i, j;

    /*
        可用于对比的输入方式：
        1- 都用C方式输入：
            scanf("%d", &i);
            scanf("%d", &j);

        2- 都用C++方式输入：
            cin >> i;
            cin >> j;

        3- 混合输入，见下：
    */

    scanf("%d", &i); //用C的方式输入  i
    cin >> j; // 用C++的方式输入 j

    cout << i << ", " << j << endl;

    return 0;
}
