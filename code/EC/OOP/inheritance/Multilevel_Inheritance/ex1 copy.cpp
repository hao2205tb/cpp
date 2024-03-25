#include <iostream>
using namespace std;

class base1{
    public: 
        int a;
};
class base2{
    public: 
        int a;
};

class child1: protected virtual base1, protected virtual base2{
    public:
        void func(){
            base1::a++;
            base2::a+=2;
        }
        void show(){
            cout << base1::a << endl;
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