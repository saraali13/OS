#include "school.h"
#include "course.h"
#include <iostream>
using namespace std;

Student::Student(const string& name) : name(name) {}

void Student::enroll(Course* course) 
{
    courses.push_back(course);
}

void Student::display_Courses() const 
{
    cout << "Student: " << name << " is enrolled in:\n";
    for (const auto& course : courses) 
    {
        cout << "- " << course->getName() << "\n";
    }
}

string Student::getName() const 
{
    return name;
}

