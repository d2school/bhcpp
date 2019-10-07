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
        if (name == "志玲")
        {
            cout << "大家好，我是志玲，请多多关照！" << endl;
        }
        else
        {
            cout << "Hi, my name is " << name << "." << endl;
        }
    }

    std::string name;
};

int main()
{
    Person xiaoA;
    xiaoA.name = "Xiao A";

    Person* zhiLing = new Person;
    zhiLing->name = "志玲";

    xiaoA.Introduction();
    zhiLing->Introduction();

    delete zhiLing;

    return 0;
}
