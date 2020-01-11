#include <iostream>

using namespace std;

int main()
{
    int* a;
    cout << "----代码: int a;----" << endl;
    cout << "指针变量a的值为: " << a 
        << "，这就是a指向的地址，现在是个不确定的值。" << endl;
    cout << "指针变量a的内存地址为: " << &a << endl;
    cout << "指针变量a占用的内存尺寸为: " << sizeof(a) << "个字节" << endl;
    cout << "指针变量a的运行期类型信息名称为: " << typeid(a).name() << endl;
    
    a = new int;
    cout << "----代码: a = new int;----" << endl;
    cout << "指针变量a的值为: " << a 
        << "，这就是a指向的地址。" << endl;
    cout << "指针变量a的内存地址为: " << &a << endl;
    cout << "指针变量a占用的内存尺寸为: " << sizeof(a) << "个字节" << endl;
    cout << "指针变量a的运行期类型信息名称为: " << typeid(a).name() << endl;
    cout << "指针变量a所向指的内存中存的数据现在是：" << *a 
        << ",现在是个不确定的值。" << endl;
    
    *a = 123;
    cout << "----代码: a = new int;----" << endl;
    cout << "指针变量a的值为: " << a 
        << "，这就是a指向的地址。" << endl;
    cout << "指针变量a的内存地址为: " << &a << endl;
    cout << "指针变量a占用的内存尺寸为: " << sizeof(a) << "个字节" << endl;
    cout << "指针变量a的运行期类型信息名称为: " << typeid(a).name() << endl;
    cout << "指针变量a所向指的内存中存的数据现在是：" << *a << endl;
    
    cout << "指针变量a所向指的内存中存的数据占用的内存尺寸为：" << sizeof(*a) << endl;
    
    return 0;
}
