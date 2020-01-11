#include <iostream>

using namespace std;

int main()
{
    unsigned int bytes = 0;
     
    while(true)
    {
        try
        {
            new char [1024 * 4];
            bytes += 1024 * 4;
        }
        catch(std::exception const & e)
        {
            std::cout << e.what() << std::endl;
            break;
        }
    }
    
    std::cout << bytes << "bytes" << std::endl;
    
    return 0;
}
