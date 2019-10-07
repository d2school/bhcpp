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
    { //第一层
        Object* o1 = new Object();
        { //嵌套的第一层
            delete o1; //OK
        } //嵌套语句块结束
    } //第一层结束

    return 0;
}
