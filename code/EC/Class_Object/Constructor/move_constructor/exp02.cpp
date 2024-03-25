// C++ program with declaring the
// move constructor
#include <iostream>
using namespace std;

// Move Class
class A{
	public:
		int *data;

		A(int data){
			this->data = new int;
			*this->data = data; 
			cout << "parameter constructor \n";
		}

		A(A&& source){
			cout << "move call " << *source.data;

		}
};

void movefun(A &&a){

}

// Driver Code
int main()
{
	A a(5);
	A a1(static_cast<A&&>(a)); // move function is static cast that cast lvalue to rvalue

	// movefun(a);
	// movefun(A{5});

	return 0;
}
