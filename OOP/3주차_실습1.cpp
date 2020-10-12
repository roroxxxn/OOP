// (실습 1) 아래 코드의 컴파일 에러를 해결하여, main 함수의 cout 구문이 실행 되도록 해보세요. 단, main 함수는 수정하지 말것.

#include<iostream>
class SetValue
{
public:
	int x, y;
};

int main()
{
	SetValue obj;
	obj.x = 33;
	obj.y = 44;
	std::cout << "X= " << obj.x << " , Y= " << obj.y << std::endl;
	system("pause");
	return 0;
}