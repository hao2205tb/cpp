#include <iostream>
using namespace std;

class base{
    public: 
        int a;
};
class base2{
    public: 
        int a;
};

class child1 : public base, public base2{
    public:
        
        void func(int c, int b){
            // this->base1::a = c;
            a = c; // ERROR
        }
};

int main(){
    child1 c{1, 2};
    return 0;
}