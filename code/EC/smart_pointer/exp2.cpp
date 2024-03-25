// C++ program to demonstrate working of a Pointers
#include <iostream>
using namespace std;

void fun(int i)
{
	int* p = new int;
    *p = i;
    cout << *p << " ";
}

int main()
{
	for (int i=1; i<1000; i++){
        fun(i);
    }
}
