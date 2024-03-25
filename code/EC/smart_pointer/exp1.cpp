#include <iostream>

using namespace std;

template <typename T> 
class Sptr{
private:
    T* ptr;

public:
    explicit Sptr(T* ptr = nullptr): ptr(ptr){}

    // Overloading dereferencing operator
    T& operator*(){return *ptr;} 

    // Destructor
    ~Sptr(){delete(ptr);}
};

int main(){

    Sptr<int> p(new int);
    *p = 20;
    return 0;
}