#include <iostream>
#include <vector>
#include "student.h"

Student::Student() {
    this->name = "John Doe";
}

Student::Student(std::string name) {
    this->name = name;
    this->gpa = 0;
}

void Student::calculate() {
    int total = 0;
    for (int grade : this->grades) {
        total += grade;
    }
    this->gpa = (double)total / this->grades.size();
}

double Student::get_gpa() {
    return this->gpa;
}

std::string Student::student_info() {
    return "Student Name: " + name + "\n" + "Grade Point Average: " + std::to_string(get_gpa());
}

void Student::show_grades() {
    int counter = 1;
    for (int grade : this->grades) {
        std::cout << "Assignment " << counter << ": " << grade << std::endl;
        ++counter;
    }
}

void Student::enter_grade(int grade) {
    this->grades.push_back(grade);
    calculate();
}

