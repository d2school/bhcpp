#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    if (name == "÷æ¡·")
    {
        cout << "Hi! ÷æ¡·£¨÷æ¡·ƒ„∫√°£ƒ„—›–°««£¨∫√∫√∞Ùƒÿ°´°´" << endl;
    }
    else if (name == "ºŒ¡·")
    {
        cout << "Hi! ºŒ¡·£¨ºŒ¡·ƒ„∫√°£≤ªµ§∫√ÕÊ∞…£°" << endl;
    }
    else
    {
        cout << "Hello! " << name << "." << endl;
    }
}

int main()
{
    string name;

    cout << "Please input the name: ";
    getline(cin, name);
    Hello(name);

    cout << "Please input the name: ";
    getline(cin, name);
    Hello(name);
    return 0;
}
