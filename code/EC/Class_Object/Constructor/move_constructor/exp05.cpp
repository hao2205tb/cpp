// C++ program with declaring the
// move constructor
#include <iostream>
#include <vector>
using namespace std;

// Move Class
class Move {
private:
	int* data;

public:

	// Constructor
	Move(int d)
	{
		// Declare object in the heap
		data = new int;
		*data = d;
		cout << "Constructor is called for "<< d << endl;
	};

	// Copy Constructor
	Move(const Move& source)
		: Move{ *source.data }
	{

		cout << "Copy Constructor is called -" << "Deep copy for " << *source.data << endl;
	}

	// // Move Constructor
	// Move(Move&& source)
	// 	: data{ source.data }
	// {

	// 	cout << "Move Constructor for " << *source.data << endl;
	// 	source.data = nullptr;
	// }

	// Destructor
	~Move()
	{
		if (data != nullptr)
			cout << "Destructor is called for " << *data << endl;
		else
			cout << "Destructor is called" << " for nullptr " << endl;

		delete data;
	}
};

// Driver Code
int main()
{
	// Vector of Move Class
	vector<Move> vec;

	// Inserting Object of Move Class
	Move m {30};
	m.~Move();
	return 0;
}
