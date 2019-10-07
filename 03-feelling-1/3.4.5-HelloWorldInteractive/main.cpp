#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    cout << "Hello! " << name << "." << endl;
}

int main()
{    
    string name;
    
    cout << "Please input the name: ";
    getline(cin, name);
    Hello(name);
    
    name = "BOSS";
    Hello(name);
    return 0;
}
