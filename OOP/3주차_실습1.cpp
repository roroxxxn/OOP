// (�ǽ� 1) �Ʒ� �ڵ��� ������ ������ �ذ��Ͽ�, main �Լ��� cout ������ ���� �ǵ��� �غ�����. ��, main �Լ��� �������� ����.

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