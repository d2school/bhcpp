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
    {
        Object* o1 = new Object();
    }

    delete o1; //编译不通过，因为 o1 此处不可见

    Object o2;

    return 0;
}
