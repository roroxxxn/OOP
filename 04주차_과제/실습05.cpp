#include <iostream>

// 레퍼런스로 전달 시(call by reference) 다음과 같이 매개변수를 참조형 변수로 주고 함수 호출 시 lvalue를 전달한다.
// 레퍼런스 형태로 변수를 받게 되면 매개변수 a를 통해 num 값(원본)에 접근할 수 있게 된다. 
// 사실 정확히 말하면 int& ref = num 과 같이 참조 변수를 만들 경우 ref라는 변수는 따로 메모리 공간에 할당되지 않는다.

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