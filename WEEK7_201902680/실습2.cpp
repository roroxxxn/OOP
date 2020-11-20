#include <iostream>
bool funcA() {
    int c;
    std::cout << "input(number) : ";
    std::cin >> c;
    if (c < 10) { //Let's assume this is exception
        throw std::out_of_range(NULL); // throw문을 통해 예외를 발생시켜 인자를 catch문으로 던진다.
    }
    return 0;
}

int main() {

    try {
        funcA();
    }
    catch (std::out_of_range& e) { 
        std::cout << "Exception : Invalid Input!!" << std::endl;
    }
    // try블록에서 예외가 발생하지 않았으면 catch블록을 실행하지 않지만
    // 만약 예외가 발생하였다면 catch블록에서 throw가 던진 인자를 받아 예외처리를 실행한다.
}