#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
using namespace std;

class Course; 

class Teacher 
{
private:
    string name;
    vector<Course*> courses;

public:
    Teacher(const string& name);
    void assign_Course(Course* course);
    void display_Courses() const;
    string getName() const;
};

#endif
