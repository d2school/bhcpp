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

    virtual void Introduction()  //基类中的虚函数
    {
        cout << "Hi, my name is " << name << "." << endl;
    }

    std::string name;
};

struct Beauty : public Person
{
    void Introduction() override //在派生类中明确指明该函数在基类中就是虚函数 (C++11)
    {
        cout << "大家好，我是美女: " << name << "，请多多关照！" << endl;
    }
};

int main()
{
    Person* xiaoA = new Beauty; //小A名为 Person，但实为 Beauty
    xiaoA->name = "Xiao A";

    xiaoA->Introduction();  //现在，小A终于可以宣告世界，我（也）是美女！！！
    delete xiaoA;

    Beauty* zhiLing = new Beauty; //志玲名实一致，全是Beauty
    zhiLing->name = "志玲";

    zhiLing->Introduction();
    delete zhiLing;

    return 0;
}
