#include <iostream>
using namespace std;
class A{
    public:
        
};

int main(){
    A a{10};
    a.func(A{10});
    // A(A{10});
    return 0;
}