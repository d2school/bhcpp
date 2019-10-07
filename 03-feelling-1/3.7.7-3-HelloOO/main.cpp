#include <iostream>

using namespace std;

struct Object
{
    Object()
    {
        std::cout << "Hello world!" << endl;
    }

    ~Object()
    {
        std::cout << "Bye-bye world!" << endl;
    }
};

int main()
{
    Object* o1; //先定义一个堆变量

    {
       o1 = new Object(); //再为它初始化
    }

    delete o1; //释放它 （o1此时可见）

    return 0;
}
