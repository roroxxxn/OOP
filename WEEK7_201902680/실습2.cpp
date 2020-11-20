#include <iostream>
bool funcA() {
    int c;
    std::cout << "input(number) : ";
    std::cin >> c;
    if (c < 10) { //Let's assume this is exception
        throw std::out_of_range(NULL); // throw���� ���� ���ܸ� �߻����� ���ڸ� catch������ ������.
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
    // try��Ͽ��� ���ܰ� �߻����� �ʾ����� catch����� �������� ������
    // ���� ���ܰ� �߻��Ͽ��ٸ� catch��Ͽ��� throw�� ���� ���ڸ� �޾� ����ó���� �����Ѵ�.
}