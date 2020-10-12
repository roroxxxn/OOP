#include <iostream>
using namespace std;
int i;
class A
{
public:
    ~A() // 社瑚切( <-> 持失切 )
    {
        i = 10;
    }
};
int foo()
{
    i = 3;
    A ob;
    return i;
}
int main()
{
    cout << foo() << endl;
    return 0;
}