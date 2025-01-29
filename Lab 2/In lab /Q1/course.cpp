#include "course.h"
#include <iostream>
using namespace std;

Course::Course(const string& name) : name(name) {}

void Course::enroll_Student(Student* student) {
    students.push_back(student);
    student->enroll(this);
}

void Course::assign_Teacher(Teacher* teacher) {
    teachers.push_back(teacher);
    teacher->assign_Course(this);
}

void Course::display_Students() const {
    cout << "Course: " << name << " has the following students enrolled:\n";
    for (const auto& student : students) {
        cout << "- " << student->getName() << "\n";
    }
}

void Course::display_Teachers() const {
    cout << "Course: " << name << " is taught by:\n";
    for (const auto& teacher : teachers) {
        cout << "- " << teacher->getName() << "\n";
    }
}

string Course::getName() const {
    return name;
}

