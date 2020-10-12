// (실습 2) "실습 1"의 코드가 OOP의 추상화 및 캡슐화 개념을 만족하도록 바꾸어 보세요.
// 단, SetValue 클래스의 기존 구문은 수정하지 않고 새로운 멤버 함수만 추가하여 수정할 것.
// * 추상화 : 클래스 내부의 정보를 외부로부터 숨김
// * 캡슐화 : 클래스 멤버 변수와 멤버 함수와의 연결(binding)-- > 내부 변수 접근을 위한 인터페이스 제공#include <iostream>class SetValue
{
private: // 추상화
	int x, y;
	/* 이곳에 코드 추가 */
public:
	void setXY(int a, int b) { // 캡슐화
		x = a;
		y = b;
	}
	void show() {
		std::cout << "X= " << x << " , Y= " << y << std::endl;
	}
};

int main()
{
	SetValue obj;
	obj.setXY(33, 44);
	obj.show();
	system("pause");
	return 0;
}