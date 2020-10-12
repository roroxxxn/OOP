#include <string>
#include<iostream>

class Animal {
private:
	std::string name;
public:
	Animal() {};
	Animal(std::string name) : name(name) {};
	void showName() {
		std::cout << "Name is " << name << std::endl;
	}
	// ������ �����ε�!
	Animal& operator+(const Animal& a) {
		this->name += a.name;
		return *this; // �ǽ� 3�� �ٸ� ���� ����Ÿ���� animal&, this �ڱ� �ڽ��̱� ������ dog
	}
};
int main() {
	Animal cat("Nabi");
	cat.showName();
	Animal dog("Jindo");
	dog.showName();
	Animal catDog = dog + cat;
	catDog.showName();
	dog.showName(); // jindonabi ����Ѵ� ��???
	getchar();
	return 0;
}