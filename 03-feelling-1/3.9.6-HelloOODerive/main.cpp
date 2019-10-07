#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person()
    {
        cout << "Wa~Wa~" << endl;
    }

    ~Person()
    {
        cout << "Wu~Wu~" << endl;
    }

    void Introduction()
    {
        cout << "Hi, my name is " << name << "." << endl;
    }

    //普通人，增加一个唱歌成员函数
    void Sing()
    {
        std::cout << "@ # $ % ^ &" << std::endl;
    }

    std::string name;
};

struct Beauty : public Person
{
    void Introduction()
    {
        cout << "大家好，我是美女: " << name << "，请多多关照！" << endl;
    }
};

int main()
{
    Person xiaoA;
    xiaoA.name = "Xiao A";

    Beauty* zhiLing = new Beauty; //是的，志玲跟我们从此不是一“类”
    zhiLing->name = "志玲";

    //新加一个美女，改用栈变量
    Beauty jiaLing;
    jiaLing.name = "嘉玲";

    xiaoA.Introduction();
    zhiLing->Introduction();
    jiaLing.Introduction();

    delete zhiLing;

    Beauty power;
    power.Sing(); //美女从基类（人类）继承的功能

    return 0;
}
