#include <iostream>
using namespace std;

class base{
    public: 
        int a;
        base (){ a = 0; cout << &a<< "base \n";}
        ~base (){ a = 0; cout << &a<< "de ~ base \n";}
};
class base1:protected base{
    public:
        base1(){
            cout << &a<< "base 1 \n";
        }
};
class base2:protected base{
    public:
        base2(){
            cout << &a<< "base 2 \n";
        }
};

class child1: protected base1, protected base2{
    public:

        void func(){
            base1::a++;
            base2::a++;
            // base::a; // error
            
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