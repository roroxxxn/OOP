// (�ǽ� 2) "�ǽ� 1"�� �ڵ尡 OOP�� �߻�ȭ �� ĸ��ȭ ������ �����ϵ��� �ٲپ� ������.
// ��, SetValue Ŭ������ ���� ������ �������� �ʰ� ���ο� ��� �Լ��� �߰��Ͽ� ������ ��.
// * �߻�ȭ : Ŭ���� ������ ������ �ܺηκ��� ����
// * ĸ��ȭ : Ŭ���� ��� ������ ��� �Լ����� ����(binding)-- > ���� ���� ������ ���� �������̽� ����#include <iostream>class SetValue
{
private: // �߻�ȭ
	int x, y;
	/* �̰��� �ڵ� �߰� */
public:
	void setXY(int a, int b) { // ĸ��ȭ
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