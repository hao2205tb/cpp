#include <iostream>
using namespace std;

class base{
    public: 
        int a;
};
class base2{
    public: 
        int b;
};

class child1 : public base, public base2{
    public:
        int d;
        // child1(int a, int b): a(a), b(b){} // compile error
        child1(int a, int b): d(a){
            this->a = a;
            this->b = b;
        }
};

int main(){
    child1 c{1, 2};
    return 0;
}