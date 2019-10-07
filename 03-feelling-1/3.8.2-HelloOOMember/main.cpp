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

    void Introduce()
    {
        cout << "Hi, my name is " << name << "." << endl;
    }

    std::string name;
};

int main()
{
    Person xiaoA;
    xiaoA.name = "Xiao A";

    Person *xiaoB = new Person;
    xiaoB->name = "Xiao B";

    xiaoA.Introduce();
    xiaoB->Introduce();

    delete xiaoB;

    return 0;
}
