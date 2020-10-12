// (실습 3) 다음 프로그램의 확장자를.c 와.cpp의 두 가지 경우로 실행(컴파일)해 보세요.
// 각 경우에 에러가 나거나 나지 않는 이유에 대해 생각해 보세요.

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