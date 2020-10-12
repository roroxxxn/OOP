// (실습 4) 아래 프로그램은 C++을 이용하여 간단한 스택을 구현한 것이다.
// 스택은 데이터를 보관하기 위한 저장소로서, push를 할경우 데이터가 스택에 들어가고,
// pop을 할 경우, 스택의 가장 위에 있는 데이터가 스택에서 나온다.스택의 현재 위치를
// 가르키는 스택 포인터의 값은 pop을 할 경우 줄어들고, push를 할 경우 증가한다.
// 아래 그림을 보고 이해해 보자.

#include <iostream>
#define MAXSTACKSIZE 1000 // 스택에 저장되어있는 데이터의 최대 크기

class Stack {
	int top; // 스택의 최상단을 가리킴
public:
	int a[MAXSTACKSIZE]; //스택
	Stack() { top = -1; } //스택의 꼭대기 값 초기화
	bool push(int x);
	int pop();
};
bool Stack::push(int x)
{
	if (top >= (MAXSTACKSIZE - 1)) {
		std::cout << "오류: 스택이 넘쳤습니다." << std::endl;
		return false;
	}
	else {
		// 코드 구현: 스택에 데이터 넣기
		a[top + 1] = x;
		top = top + 1;

		std::cout << x << " 이 스택에 들어갔습니다." << std::endl;
		return true;
	}
}
int Stack::pop()
{
	if (top < 0) {
		std::cout << "오류: 스택이 비었습니다." << std::endl;
		return 0;
	}
	else {
		//코드 구현 : 스택에서 데이터 빼기
		int x = a[top];
		a[top] = NULL;
		top = top - 1;
		// int x;
		// x = a[top];
		// top--;
		return x;
	}
}
int main()
{
	class Stack s;
	s.push(7);
	s.push(88);
	s.push(999);
	std::cout << s.pop() << " 을 스택에서 꺼냈습니다." << std::endl;
	std::cout << s.pop() << " 을 스택에서 꺼냈습니다." << std::endl;
	std::cout << s.pop() << " 을 스택에서 꺼냈습니다." << std::endl;
	system("pause");
	return 0;
}