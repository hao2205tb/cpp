#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <ctime>
#include <vector>

using namespace std;

enum sex_t{
    male = 0,
    female = 1
};

enum gradeLevel_t{
    Excellent, Good, Average, Below, Weak
};

class Student{
    public:
        string ID;
        string fullName;
        time_t doB;
        sex_t sex;
        string phoneNumber;
        string universityName;
        gradeLevel_t gradeLevel; 

        virtual void showMyInfor(){
            cout << "Student info" << endl;
        }

};

class NormalStudent: public Student{
    public:
        float englishScore;
        float entryTestScore;
    
    void showMyInfor(){
            cout << "Normal student info" << endl;
        }
    
};

class GoodStudent: public Student{
    public:
        float gpa;
        string bestRewardName;

        void showMyInfor(){
            cout << "Good student info" << endl;
        }
};

class Exception{
    public: 
        virtual bool invalidFullNameException(string) = 0;
        virtual bool invalidDOBException(string) = 0;
        virtual bool invalidPhoneNumberException(string) = 0;
        virtual void other_exception(string) = 0;
};

class Selectable{
    public:
        virtual bool select_students(vector<Student>& list_students) = 0;
};

class Class: public Selectable, public Exception{
    public:
        string ID;
        string name;
        vector<Student> list_students;

        void add_student(Student &st){

        }

        void display_students(){

        }

        virtual bool invalidFullNameException(string name) = 0;
        virtual bool invalidDOBException(string doB) = 0;
        virtual bool invalidPhoneNumberException(string phoneNumber) = 0;
        virtual void other_exception(string input) = 0;

        virtual bool select_students(vector<Student>& list_students) = 0;

};

class InputFile{
public:
    static void parser_inputfile(string filepath, vector<string>& f_content){
        fstream file;
        file.open(filepath, ios::in);
        
        string str;
        string line;

        while(getline(file, line)){
            vector<string> row;
            f_content.push_back(line);
            // cout << endl;  
        }

        file.close();
    }

    static void get_classname(const vector<string>& f_content){

    }

    static bool is_goodstudent(string gradeLevel){
        
    }

    Student get_student(string line){
        
    }

};

class System{
    private:
        vector<Class> list_class;

    public: 
        void get_dB(){

        }
        
        void display_classes(){

        }

        void add_class(Class &new_cls){

        }

};

int main(){

    string filepath = "../data/student_data.csv";
    vector<vector<string>> dB;

    InputFile::parser_inputfile(filepath, dB);

    // for (const auto& row: dB){
    //     for (const auto& cell: row){
    //         cout << " " << cell;
    //     }
    //     cout << endl;
    // }

    cout << InputFile::is_goodstudent(dB[7]);


    return 0;
}