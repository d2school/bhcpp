#include <iostream>

using namespace std;

struct Object
{
    Object()
    {
        std::cout << "Hello world!" << endl;
    }
};

int main()
{
    Object o;

    return 0;
}
