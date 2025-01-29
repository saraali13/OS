#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
using namespace std;

class Course; 

class Student 
{
private:
    string name;
    vector<Course*> courses;

public:
    Student(const string& name);
    void enroll(Course* course);
    void display_Courses() const;
    string getName() const;
};

#endif

