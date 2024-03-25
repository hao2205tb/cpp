#include <iostream>
using namespace std;

class base{
    public: 
        int a;
};
class base2:protected base{
};

class child1: protected base2{
    public:
        void func(){
            base::a++;
            base2::a+=2;
        }
        void show(){
            cout << base::a << endl;
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