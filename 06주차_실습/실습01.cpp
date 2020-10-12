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
	static int number_of_cats; // static 변수를 클래스 내에 선언한다.
};

int My_cat::number_of_cats = 0; // 클래스 외부에서 값을 초기화 한다 !!!!!!!! 중요 !!!!!!!!

My_cat::My_cat() :age(20), name(NULL), weight(10) {

	++My_cat::number_of_cats; // 생성자를 통해 객체를 생성할 때 마다 객체 수를 증가시킨다.

	}
My_cat::My_cat(int x, const char* cat_name) : weight(10) {
	age = x;
	name = new char[strlen(cat_name) + 1];
	strcpy(name, cat_name);

	++My_cat::number_of_cats; // 생성자를 통해 객체를 생성할 때 마다 객체 수를 증가시킨다.
}
My_cat::My_cat(const My_cat& cat) : weight(10) { //Copy constructor
	std::cout << "Copy constructor invocation ! " << std::endl;
	age = cat.age;
	name = new char[strlen(cat.name) + 1];
	strcpy(name, cat.name);

	++My_cat::number_of_cats; // 복사생성자를 통해 객체를 생성할 때에도 객체 수를 증가시킨다.
}
My_cat::~My_cat() { //Destructor
	if (name) delete[] name;
	--My_cat::number_of_cats; // Destructor을 통해 객체를 생성할 때에도 객체 수를 감소시킨다.
}
void My_cat::show_status() const {
	std::cout << "My Cat Name :: " << name << std::endl;
	std::cout << " Age : " << age << std::endl;
	std::cout << " Weight : " << weight << std::endl;
	std::cout << " Current Number of Cats : " << number_of_cats << std::endl;
}
int main() {
	My_cat cat1(3, "Nabi"); //Cat 1 생성
	cat1.show_status();
	My_cat cat2 = cat1; //Cat 2 복사 생성
	cat2.show_status();
	My_cat cat3(4, "ToTo"); //Cat 3 생성
	cat3.show_status();
	getchar();
	return 0;
}