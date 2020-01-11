#include <iostream>

using namespace std;

int main()
{
    int a;

    cout << "----代码: int a;----" << endl;
    cout << "变量a的值为: " << a << endl;
    cout << "变量a的内存地址为: " << &a << endl;
    cout << "变量a占用的内存尺寸为: " << sizeof(a) << "个字节" << endl;
    cout << "变量a的运行期类型信息名称为: " << typeid(a).name() << endl;

    a = 1;

    cout << "----代码: a = 1; 之后----" << endl;
    cout << "变量a的值为: " << a << endl;
    cout << "变量a的内存地址为: " << &a << endl;
    cout << "变量a占用的内存尺寸为: " << sizeof(a) << "个字节" << endl;
    cout << "变量a的运行期类型信息名称为: " << typeid(a).name() << endl;

    return 0;
}
