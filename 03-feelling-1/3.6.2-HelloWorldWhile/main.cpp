#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    if (name == "志玲")
    {
        cout << "Hi! 志玲你好。你演小乔，好好棒呢～～" << endl;
    }
    else
    {
        cout << "Hello! " << name << "." << endl;
    }
}

int main()
{
    string name;

    while (true) // while (2>1)
    {
        cout << "Please input the name: ";
        getline(cin, name);
        Hello(name);
    }

    return 0;
}
