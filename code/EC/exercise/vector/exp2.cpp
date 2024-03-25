#include <iostream>
#include <initializer_list> // For std::initializer_list

template <typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    Vector():data(nullptr), size(0), capacity(0){};
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

    void push_back(T& source){
        if (size == capacity){
            capacity = (capacity == 0) ? 1 : 2 * capacity;
            T* ptr = new T[capacity];
            for (size_t i=0; i<size; i++){
                ptr[i]=data[i];
            }
            delete []data;
            data = ptr;
        }

        data[size++] = *(new T(source));
    }

    void push_back(T&& source){
        if (size == capacity){
            capacity = (capacity == 0) ? 1 : 2 * capacity;
            T* ptr = new T[capacity];
            for (size_t i=0; i<size; i++){
                ptr[i] = data[i];
            }
            delete []data;
            data = ptr;
        }
        data[size++] = *(new T(std::move(source)));
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

class A{
public:
    int* value;
    A():value(nullptr){};
    A(int v){
        value = new int;
        *value = v;
    }
    A(A& s){
        value = new int;
        *value = *s.value;
        std::cout << "copy\n";
    }
    A(A&& s):value(s.value){
        s.value = nullptr;
        std::cout << "move\n";
    }
    A& operator=(const A& other) {
        if (this != &other) {
            this->value = other.value;
        }
        return *this;
    }
};

int main() {
    Vector<int> myVector = {10, 20, 30, 40}; // Initialize with values
    std::cout << "cap: " << myVector.get_capacity() << std::endl;
    myVector.display();
    myVector.push_back(50);
    std::cout << "cap: " << myVector.get_capacity() << std::endl;
    myVector.display();

    Vector<A> vector_a;
    vector_a.push_back(A{30});
    A a{3};
    vector_a.push_back(a);
    std::cout << a.value << " " << *vector_a[1].value << std::endl;
    vector_a.push_back(std::move(a));
    std::cout << a.value << " " << *vector_a[2].value << std::endl;

    return 0;
}
