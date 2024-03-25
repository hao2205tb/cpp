#include <iostream>
#include <initializer_list> // For std::initializer_list

template <typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    // Constructor with variadic arguments
    Vector(std::initializer_list<T> args) : size(args.size()), capacity(0) {
        init_capacity(); // using recursive to increase capacity to larger size
        if (capacity) {
            data = new T[capacity];
            size_t i = 0;
            for (const T& value : args) {
                data[i++] = value;
            }
        }
    }

    void init_capacity(){
        // recursive case
        if (capacity < size) {
            if (capacity == 0){
                capacity = 1;
            }
            else capacity *=2;

            // re-call function
            init_capacity();
        }

        // base conditions
        if (size == 0){
            capacity = 0;
            return;
        }
        // if (capacity >= size) return;
    }

    size_t get_capacity(){
        return capacity;
    }

    size_t get_size(){
        return size;
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
    Vector<int> myVector = {10, 20, 30, 40, 50}; // Initialize with values
    std::cout << "cap: " << myVector.get_capacity() << std::endl;
    myVector.display();

    Vector<double> doubleVector = {1.1, 2.2, 3.3}; // Another example
    doubleVector.display();

    return 0;
}
