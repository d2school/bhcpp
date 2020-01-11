#include <iostream>

using namespace std;

struct Object
{
    Object(std::string const & name)
    {
        name_ = name;
        std::cout << name_ << ": Hello world!" << endl;
    }

    ~Object()
    {
        std::cout << name_ << ": Bye-bye world!" << endl;
    }
    
private:
    std::string name_;
};

int main()
{
    {//----------第一层开始-----------------------
        std::cout << "enter 1" << std::endl;
        Object o("a");
        
        {//----------第二层开始-----------------------
            std::cout << "enter 2" << std::endl;
            Object o("b");
            
            {//----------第三层开始-----------------------
                std::cout << "enter 3" << std::endl;
                Object o("c");
            }//----------第三层结束-----------------------
            std::cout << "exit 3" << std::endl;
            
        }//----------第二层结束-----------------------
        std::cout << "exit 2" << std::endl;
        
    }//----------第三层结束-----------------------
    std::cout << "exit 1" << std::endl;
        
    return 0;
}
