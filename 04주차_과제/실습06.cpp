#include <iostream>

int main()
{
	int a = 5;
	int& x = a;
	// or const int& x = 5;
	std::cout << x << std::endl;
}