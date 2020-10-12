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
	// 연산자 오버로딩!
	Animal& operator+(const Animal& a) {
		this->name += a.name;
		return *this; // 실습 3과 다른 점은 리턴타입이 animal&, this 자기 자신이기 때문에 dog
	}
};
int main() {
	Animal cat("Nabi");
	cat.showName();
	Animal dog("Jindo");
	dog.showName();
	Animal catDog = dog + cat;
	catDog.showName();
	dog.showName(); // jindonabi 출력한다 왜???
	getchar();
	return 0;
}