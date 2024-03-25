#include <iostream>
using namespace std;

class base{
    public: 
        int a;
        base (){ cout << "base \n";}
};
class base1:protected base{
    public:
        base1(){
            cout << "base 1 \n";
        }
};
class base2:protected base{
    public:
        base2(){
            cout << "base 2 \n";
        }
};

class child1: protected virtual base1, protected virtual base2{
    public:

        void func(){
            base1::a++;
            base2::a++;
        }
        void show(){
            // cout << base:: a << endl;
            cout << "aaaa" << base1::a << endl;
            cout << base2::a << endl;
        }
};

int main(){
    child1 c;
    c.show();
    c.func();
    c.show();
    
    return 0;
}