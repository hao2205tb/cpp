#include <iostream>
using namespace std;

class base{
    public: 
        int a;
};
class base1:protected base{
};
class base2:protected base{
};

class child1: protected base1, protected base2{
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