#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    cout << "Hello! " << name << "." << endl;
}

int main()
{
    Hello("Xiao A");
    Hello("BOSS");
    return 0;
}
