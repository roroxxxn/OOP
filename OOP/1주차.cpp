#include <iostream>
class LetDebug
{
public:
    void printNum()
    {
        short s1 = 32767;
        short s2 = 1;
        int s3 = (short)s1 + s2;
        std::cout << s3 << std::endl;
        std::cout << "i have made a change!" << std::endl;
    }
};

int main()
{
    LetDebug* ld = new LetDebug;
    ld->printNum();

    return 0;
}

