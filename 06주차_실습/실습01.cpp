#include<iostream>

class My_cat {
	int age;
	char* name;
	int weight;

public:
	My_cat();
	My_cat(int x, const char* name);
	My_cat(const My_cat& cat);
	~My_cat();
	void show_status() const;
	static int number_of_cats; // static ������ Ŭ���� ���� �����Ѵ�.
};

int My_cat::number_of_cats = 0; // Ŭ���� �ܺο��� ���� �ʱ�ȭ �Ѵ� !!!!!!!! �߿� !!!!!!!!

My_cat::My_cat() :age(20), name(NULL), weight(10) {

	++My_cat::number_of_cats; // �����ڸ� ���� ��ü�� ������ �� ���� ��ü ���� ������Ų��.

	}
My_cat::My_cat(int x, const char* cat_name) : weight(10) {
	age = x;
	name = new char[strlen(cat_name) + 1];
	strcpy(name, cat_name);

	++My_cat::number_of_cats; // �����ڸ� ���� ��ü�� ������ �� ���� ��ü ���� ������Ų��.
}
My_cat::My_cat(const My_cat& cat) : weight(10) { //Copy constructor
	std::cout << "Copy constructor invocation ! " << std::endl;
	age = cat.age;
	name = new char[strlen(cat.name) + 1];
	strcpy(name, cat.name);

	++My_cat::number_of_cats; // ��������ڸ� ���� ��ü�� ������ ������ ��ü ���� ������Ų��.
}
My_cat::~My_cat() { //Destructor
	if (name) delete[] name;
	--My_cat::number_of_cats; // Destructor�� ���� ��ü�� ������ ������ ��ü ���� ���ҽ�Ų��.
}
void My_cat::show_status() const {
	std::cout << "My Cat Name :: " << name << std::endl;
	std::cout << " Age : " << age << std::endl;
	std::cout << " Weight : " << weight << std::endl;
	std::cout << " Current Number of Cats : " << number_of_cats << std::endl;
}
int main() {
	My_cat cat1(3, "Nabi"); //Cat 1 ����
	cat1.show_status();
	My_cat cat2 = cat1; //Cat 2 ���� ����
	cat2.show_status();
	My_cat cat3(4, "ToTo"); //Cat 3 ����
	cat3.show_status();
	getchar();
	return 0;
}