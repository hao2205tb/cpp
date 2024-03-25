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
    Vector(std::initializer_list<T> args) : data(nullptr), size(args.size()), capacity(0){
        init_capacity(); // using recursive to increase capacity to larger size
        if (capacity) {
            data = new T[capacity];
            size_t i = 0;
            for (const T& value : args) {
                data[i++] = value;
            }
        }
    }

    Vector(size_t size, T value): data(nullptr), size(size), capacity(0){
        init_capacity();
        if (capacity) {
            data = new T[capacity];
            for (size_t i=0; i<size; i++) {
                data[i] = value;
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

    void push_back(const T& source){
        if (size == capacity){
            capacity = (capacity == 0) ? 1 : 2 * capacity;
            T* ptr = new T[capacity];
            for (size_t i=0; i<size; i++){
                data[i]=ptr[i];
            }
            delete []data;
            data = ptr;
        }
        data[size++] = new T(move(source));
    }

    // Access an element by index
    T& operator[](size_t index){
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
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

    Vector<double> doubleVector(5, 4.1); // Another example
    std::cout << "cap: " << doubleVector.get_capacity() << std::endl;
    doubleVector.display();

    return 0;
}
