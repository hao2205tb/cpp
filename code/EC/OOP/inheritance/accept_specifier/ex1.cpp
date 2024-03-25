#include <iostream>
using namespace std;

class base{
    public: 
        int a;
    protected:
        int b;
    private:
        int c;
};

class child1: protected base{
    // protected: 
    //     int a;
    // protected:
    //     int b;
    // private:
    //     int c;

    public:
        int a;
        void func(){
            base::a++;
            b++;
            // c++; // error
        }
};

int main(){
    child1 c;
    // c.base::a; error
    return 0;
}