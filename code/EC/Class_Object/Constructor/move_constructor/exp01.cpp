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
};

// Driver Code
int main()
{
	A a(5);
	return 0;
}
