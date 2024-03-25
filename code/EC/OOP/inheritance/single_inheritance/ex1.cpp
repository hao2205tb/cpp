// C++ program to illustrate the above concept 

#include <iostream> 
using namespace std; 

// Ex1
class A{
    public:
        int a;
        void add(int a){ cout << "int " << a << endl;}
};
class B: public A{
    public:
        void add(double a){ cout << "double " << a << endl;}
};

int main(){
    B obj;
    obj.add(2.3);
    obj.add(3);
    return 0;
}