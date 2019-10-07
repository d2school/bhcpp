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

    std::string name;
};

int main()
{
    Person xiaoA;
    xiaoA.name = "Xiao A";

    Person *xiaoB = new Person;
    xiaoB->name = "Xiao B";

    cout << xiaoA.name << endl;
    cout << xiaoB->name << endl;

    delete xiaoB;
    return 0;
}
