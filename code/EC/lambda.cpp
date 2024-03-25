#include <iostream>

class A{
    
}

int main() {
    MyClass obj1, obj2;
    // Call the appropriate overload based on the argument type
    obj1.fun(obj2, obj2); // Calls the lvalue overload
    obj1.fun(MyClass(), MyClass()); // Calls the rvalue overload
    return 0;
}
