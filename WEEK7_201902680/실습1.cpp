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

/* (�ǽ� 1-1) �м���� :
   - ��� ���� :
   Executed in B
   Destructor execution: B
   Executed in A
   Destructor execution: A

   try��Ͽ��� throw�� �߻����� �ʾұ� ������
   ���ʷ� funcB�� ��¹�, ��ü b�� destructor ��¹�, funcA�� ��¹�, ��ü a�� destructor ��¹��� ����Ѵ�.
   ���ܰ� �߻����� �ʾ����Ƿ� catch����� ������� �ʴ´�.
*/

/* (�ǽ� 1-2) �м���� :    - ��� ���� :    Destructor execution: B
    Destructor execution: A
    Exception : Exception from funcB!        try��Ͽ��� throw�� �߻��Ͽ����Ƿ� try��� �� throw ������ ������� ������� �ʴ´�.    ���� funcB�� funcA�� ��¹��� ��µ��� �ʰ� �� �Լ��� ����Ǹ� destructor�� ��¹��� ���ʷ� ��µȴ�.    �׸��� throw��ɿ� ���� ���ڷ� "Exception from funcB!" �� �������Ƿ�     catch��� �̸� �޾� ����ó���� �����Ѵ�.*/