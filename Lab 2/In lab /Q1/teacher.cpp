#include "course.h"
#include "teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher(const string& name) : name(name) {}

void Teacher::assign_Course(Course* course) 
{
    courses.push_back(course);
}

void Teacher::display_Courses() const 
{
    cout << "Teacher: " << name << " is teaching:\n";
    for (const auto& course : courses) 
    {
        cout << "- " << course->getName() << "\n";
    }
}

string Teacher::getName() const 
{
    return name;
}
