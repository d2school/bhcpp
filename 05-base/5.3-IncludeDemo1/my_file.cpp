#include "my_file.hpp" //包含自定义的头文件

#include <iostream> //包含标准库文件

using namespace std;

MyStruct::MyStruct()
{
    cout << "MyStruct Construct." << endl;
}

MyStruct::~MyStruct()
{
    cout << "MyStruct Destruct." << endl;
}

void my_function(int year, int month, int day)
{
    cout << year << '-' << month << '-' << day << endl;
}
