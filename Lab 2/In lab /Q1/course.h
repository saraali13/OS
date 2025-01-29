#ifndef COURSE_H
#define COURSE_H


#include <string>
#include <vector>
#include "school.h"
#include "teacher.h"
using namespace std;


class Course 
{
private:
    string name;
    vector<Student*> students;
    vector<Teacher*> teachers;

public:
    Course(const std::string& name);
    void enroll_Student(Student* student);
    void assign_Teacher(Teacher* teacher);
    void display_Students() const;
    void display_Teachers() const;
    string getName() const;
};

#endif

