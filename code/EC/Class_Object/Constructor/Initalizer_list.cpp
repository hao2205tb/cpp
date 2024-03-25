/*
Initalizer list

*/

#include <iostream>

class B{
    public:
        int a;
        B(int a): a(a){}
};

class A{
    public:
        const int t;
        int &r;
        B b; // not have default constructor
        A(int t1, int &r1, B b1):t(t1), r(r1), b(b1){

        }
};

