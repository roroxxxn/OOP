// (�ǽ� 4) �Ʒ� ���α׷��� C++�� �̿��Ͽ� ������ ������ ������ ���̴�.
// ������ �����͸� �����ϱ� ���� ����ҷμ�, push�� �Ұ�� �����Ͱ� ���ÿ� ����,
// pop�� �� ���, ������ ���� ���� �ִ� �����Ͱ� ���ÿ��� ���´�.������ ���� ��ġ��
// ����Ű�� ���� �������� ���� pop�� �� ��� �پ���, push�� �� ��� �����Ѵ�.
// �Ʒ� �׸��� ���� ������ ����.

#include <iostream>
#define MAXSTACKSIZE 1000 // ���ÿ� ����Ǿ��ִ� �������� �ִ� ũ��

class Stack {
	int top; // ������ �ֻ���� ����Ŵ
public:
	int a[MAXSTACKSIZE]; //����
	Stack() { top = -1; } //������ ����� �� �ʱ�ȭ
	bool push(int x);
	int pop();
};
bool Stack::push(int x)
{
	if (top >= (MAXSTACKSIZE - 1)) {
		std::cout << "����: ������ ���ƽ��ϴ�." << std::endl;
		return false;
	}
	else {
		// �ڵ� ����: ���ÿ� ������ �ֱ�
		a[top + 1] = x;
		top = top + 1;

		std::cout << x << " �� ���ÿ� �����ϴ�." << std::endl;
		return true;
	}
}
int Stack::pop()
{
	if (top < 0) {
		std::cout << "����: ������ ������ϴ�." << std::endl;
		return 0;
	}
	else {
		//�ڵ� ���� : ���ÿ��� ������ ����
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
	std::cout << s.pop() << " �� ���ÿ��� ���½��ϴ�." << std::endl;
	std::cout << s.pop() << " �� ���ÿ��� ���½��ϴ�." << std::endl;
	std::cout << s.pop() << " �� ���ÿ��� ���½��ϴ�." << std::endl;
	system("pause");
	return 0;
}