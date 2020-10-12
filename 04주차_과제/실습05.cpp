#include <iostream>

// ���۷����� ���� ��(call by reference) ������ ���� �Ű������� ������ ������ �ְ� �Լ� ȣ�� �� lvalue�� �����Ѵ�.
// ���۷��� ���·� ������ �ް� �Ǹ� �Ű����� a�� ���� num ��(����)�� ������ �� �ְ� �ȴ�. 
// ��� ��Ȯ�� ���ϸ� int& ref = num �� ���� ���� ������ ���� ��� ref��� ������ ���� �޸� ������ �Ҵ���� �ʴ´�.

void increment(int& x)
{
	++(x);
}
int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	increment(x);
	std::cout << " After increment: " << x << std::endl;
	system("pause");
	return 0;
}