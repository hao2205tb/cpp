/*
Shalow copy and deep copy
*/

#include <iostream>
#include <cstring>

using namespace std;

class Vehicle{
    private:
        char *name;
        int classID;
        int year;

    public:
    // default constructor
    Vehicle(int classID, int year): classID(classID), year(year){};
    // move copy
    Vehicle(Vehicle &&source){
        name = source.name;
        source.name = nullptr;

        classID = source.classID;
        year = source.year;
    }
    void setName(const char *name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

};

int main(){
    Vehicle obj1(0001, 2024);
    obj1.setName("Alibaba Ver1");
    Vehicle obj2(move(obj1));
    // Vehicle obj2(static_cast<Vehicle &&>(obj1)); 
}
