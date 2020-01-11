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
    
private:
    std::string name_;
};

Object oa,ob,oc; //这里定义了三个全局变量

int main()
{
    std::cout << "main()" << std::endl;
    return 0;
}
