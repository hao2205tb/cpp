#include <iostream>
using namespace std;

class Base{
    public:
        virtual void func(){
            cout << "base\n";
        }
};

class Child: public Base{
    public:
        virtual void func(){
            cout << "child\n";
        }
};
int main(){

    Base b;
    b.func();

    Child c;
    c.func();

    Base *b_ptr = &c;
    b_ptr->func();

    return 0;
}