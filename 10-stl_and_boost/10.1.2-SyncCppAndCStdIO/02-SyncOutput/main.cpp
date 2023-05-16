#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	for (int i=0; i<3; ++i)
	{
		printf("hello from printf!\n");
		cout << "hello from cout.\n";
	}

	return 0;
}
