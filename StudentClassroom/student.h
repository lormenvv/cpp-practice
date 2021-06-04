#pragma once
#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <vector>
#include <array>

class Student {
    private:
        double gpa;
        std::vector<int> grades;
        void calculate();

    public:
        std::string name;
        Student();
        Student(std::string name);
        double get_gpa();
        std::string student_info();
        void show_grades();
        void enter_grade(int grade);
};


#endif