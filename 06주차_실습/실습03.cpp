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
	//operator+ 추가하세요
	Animal operator + (const Animal& a) { // const 있어도 없어도 상관x
		return Animal(this->name + a.name);
		// Animal temp;
		// temp.name = this->name + a.name;
		// return name;
	}

};

int main() {
	Animal cat("Nabi");
	cat.showName();
	Animal dog("Jindo");
	dog.showName();
	Animal catDog = dog + cat; //개냥이 합성
	catDog.showName();
	dog.showName();
	getchar();
	return 0;
}