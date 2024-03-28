#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class for storing result
class Result
{
private:
    string semesterName;
    float averageScore;

public:
    Result(const string &name, float score) : semesterName(name), averageScore(score) {}
};

// Base class for student
class Student
{
public:
    string studentID;
    string name;
    string dateOfBirth;
    int yearOfAdmission;
    float entryScore;
    vector<Result> results;

public:
    // Constructor
    Student(const string &id, const string &n, const string &dob, int year, float score)
        : studentID(id), name(n), dateOfBirth(dob), yearOfAdmission(year), entryScore(score) {}

    // Method to add result
    void addResult(const Result &result)
    {
        results.push_back(result);
    }
};

// Derived class for full-time student
class FullTimeStudent : public Student
{
public:
    FullTimeStudent(const string &id, const string &n, const string &dob, int year, float score)
        : Student(id, n, dob, year, score) {}

    // Method to determine if the student is full-time
    bool isFullTime() const
    {
        return true;
    }
};

// Derived class for part-time student
class PartTimeStudent : public Student
{
private:
    string trainingLocation;

public:
    PartTimeStudent(const string &id, const string &n, const string &dob, int year, float score, const string &location)
        : Student(id, n, dob, year, score), trainingLocation(location) {}

    // Method to get the training location
    string getTrainingLocation() const
    {
        return trainingLocation;
    }
};

// Singleton class for managing student records
class StudentManager
{
private:
    // Private constructor to prevent instantiation
    StudentManager() {}

    // Static instance of the singleton class
    static StudentManager *instance;

    // Private data members
    vector<Student *> students;

public:
    // Static method to get the instance of the singleton class
    static StudentManager *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new StudentManager();
        }
        return instance;
    }

    // Method to add a student to the list
    void addStudent(Student *student)
    {
        students.push_back(student);
    }

    // Method to get the list of students
    vector<Student *> getStudents() const
    {
        return students;
    }
};

// Initialize the static instance
StudentManager *StudentManager::instance = nullptr;
int main()
{
    // Usage example
    StudentManager *manager = StudentManager::getInstance();

    FullTimeStudent *fullTimeStudent = new FullTimeStudent("SV001", "John Doe", "2000-01-01", 2022, 8.5);
    fullTimeStudent->addResult(Result("Semester 1", 8.0));
    fullTimeStudent->addResult(Result("Semester 2", 7.5));

    manager->addStudent(fullTimeStudent);

    PartTimeStudent *partTimeStudent = new PartTimeStudent("SV002", "Jane Smith", "2001-02-02", 2021, 7.8, "Cà Mau");
    partTimeStudent->addResult(Result("Semester 1", 7.5));
    partTimeStudent->addResult(Result("Semester 2", 8.0));

    manager->addStudent(partTimeStudent);

    // Retrieve list of students from manager
    vector<Student *> students = manager->getStudents();

    // Access student data
    for (const auto &student : students)
    {
        cout << "Student ID: " << student->studentID << endl;
        cout << "Name: " << student->name << endl;
        cout << "Date of Birth: " << student->dateOfBirth << endl;
        cout << "Year of Admission: " << student->yearOfAdmission << endl;
        cout << "Entry Score: " << student->entryScore << endl;

        cout << endl;
    }

    return 0;
}