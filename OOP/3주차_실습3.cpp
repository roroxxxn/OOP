// (실습 3) 다음 프로그램의 확장자를.c 와.cpp의 두 가지 경우로 실행(컴파일)해 보세요.
// 각 경우에 에러가 나거나 나지 않는 이유에 대해 생각해 보세요.

// .cpp 에서만 실행된다.
// c++은 객체지향 언어이기 때문에 다형성이라는 특징을 가지고 있다. 
// 하지만 c는 객체지향 언어가 아니기 때문에 같은 이름을 가지고 있지만,
// 매개변수가 서로 다른 함수가 존재할 수 없다.

#include <stdio.h>
void print(int var)
{
	printf("Integer number: %d \n", var);
}
void print(float var)
{
	printf("Float number: %f \n", var);
}
void print(int var1, float var2)
{
	printf("Integer number: %d \n", var1);
	printf(" and float number: %f", var2);
}
int main()
{
	int a = 7;
	float b = 9;
	print(a);
	print(b);
	print(a, b);
	return 0;
}