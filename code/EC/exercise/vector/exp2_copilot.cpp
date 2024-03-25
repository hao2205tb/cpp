#include <iostream>
#include <initializer_list> // For std::initializer_list

template <typename T>
class Vector {
private:
    T* data;
    size_t size;

public:
    // Constructor with variadic arguments
    Vector(std::initializer_list<T> args) : size(args.size()) {
        data = new T[size];
        size_t i = 0;
        for (const T& value : args) {
            data[i++] = value;
        }
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Display vector elements
    void display() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector<int> myVector = {10, 20, 30, 40}; // Initialize with values
    myVector.display();

    Vector<double> doubleVector = {1.1, 2.2, 3.3}; // Another example
    doubleVector.display();

    return 0;
}
