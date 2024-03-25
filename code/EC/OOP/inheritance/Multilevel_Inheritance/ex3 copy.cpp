#include <iostream>
using namespace std;

class base{
    public: 
        int a;
        base (){ a = 0; cout << "base \n";}
};
class base1:public virtual base{
    public:
        base1(){
            cout << "base 1 \n";
        }
};
class base2:public virtual base{
    public:
        base2(){
            cout << "base 2 \n";
        }
};

class child1: public base1, public base2{
    public:

        void func(){
            base1::a++;
            base2::a++;
            // base::a; // error
            base1::base::a ++;
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