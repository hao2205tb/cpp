// C++ program to demonstrate working of a Pointers
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

void fun(int i)
{
	Sptr<int> p (new int);
    *p = i;
    cout << *p << " ";
}

int main()
{
	for (int i=1; i<1000; i++){
        fun(i);
    }
}
