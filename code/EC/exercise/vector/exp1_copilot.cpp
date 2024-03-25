#include <iostream>
#include <stdexcept> // For std::out_of_range

template <typename T>
class Vector {
private:
    T* data; // Pointer to the dynamically allocated array
    size_t size; // Current number of elements in the vector
    size_t capacity; // Total capacity of the vector

public:
    // Constructor: Initialize an empty vector
    Vector() : data(nullptr), size(0), capacity(0) {}

    // Destructor: Clean up memory
    ~Vector() {
        delete[] data;
    }

    // Add an element to the end of the vector
    void push_back(const T& value) {
        if (size == capacity) {
            // Need to resize the array
            capacity = (capacity == 0) ? 1 : 2 * capacity;
            T* newData = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }

    // Access an element by index
    T& operator[]{
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Get the current size of the vector
    size_t getSize() const {
        return size;
    }
};

int main() {
    Vector<int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    std::cout << "Vector size: " << myVector.getSize() << std::endl;
    std::cout << "Elements: ";
    for (size_t i = 0; i < myVector.getSize(); ++i) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
