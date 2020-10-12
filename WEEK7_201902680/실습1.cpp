#include <iostream>
#include <stdexcept>

class Test {
public:
    Test(char id) : id_(id) {}
    ~Test() {
        std::cout << "Destructor execution: "
            << id_ << std::endl;
    }
private:
    char id_;
};
int funcB() {
    Test r('B');
    // throw std::runtime_error("Exception from funcB!\n");
    std::cout << "Executed in B" << std::endl;
    return 0;
}
int funcA() {
    Test r('A');
    funcB();
    std::cout << "Executed in A" << std::endl;
    return 0;
}
int main() {
    try {
        funcA();
    }
    catch (std::exception& e) {
        std::cout << "Exception : " << e.what();
    }
}

/* (실습 1-1) 분석결과 :
   - 출력 내용 :
   Executed in B
   Destructor execution: B
   Executed in A
   Destructor execution: A

   try블록에서 throw가 발생하지 않았기 때문에
   차례로 funcB의 출력문, 객체 b의 destructor 출력문, funcA의 출력문, 객체 a의 destructor 출력문을 출력한다.
   예외가 발생하지 않았으므로 catch블록은 실행되지 않는다.
*/

/* (실습 1-2) 분석결과 :    - 출력 내용 :    Destructor execution: B
    Destructor execution: A
    Exception : Exception from funcB!        try블록에서 throw가 발생하였으므로 try블록 내 throw 다음의 문장들은 실행되지 않는다.    따라서 funcB와 funcA의 출력문은 출력되지 않고 두 함수가 종료되면 destructor의 출력문이 차례로 출력된다.    그리고 throw명령에 따라 인자로 "Exception from funcB!" 을 던졌으므로     catch블록 이를 받아 예외처리를 실행한다.*/