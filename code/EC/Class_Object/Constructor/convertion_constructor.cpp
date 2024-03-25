/*
convertion constructor

*/

#include <iostream>
using namespace std;

class A{
    public:
        int a;
        int b;
        A(int a): a(a){}
};

int main(){

    A a(30);
    a = 40; // conversion constructor is call

    cout << a.a;

    return 0;

}