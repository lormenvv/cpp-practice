/* Student Grade Book Application – Keep track of students (with a student class that has their name, average, and scores) 
in a class and their grades. Assign their scores on tests and assignments to the students and figure out their average 
and grade for the class. For added complexity put the students on a bell curve. Add grade distinctions (Quiz, HW, Test, Exam) */

#include <iostream>
#include <vector>
#include <array>
#include "student.h"

void display_grades(std::array<Student, 3>& classroom) {
    for (Student s : classroom) {
        std::cout << s.student_info() << std::endl;
    }
}

int main() {
    std::array<Student, 3> classroom;
    Student sally("Sally"), john("John"), marc("Marc");

    sally.enter_grade(91);
    sally.enter_grade(91);

    john.enter_grade(12);
    john.enter_grade(57);

    marc.enter_grade(100);
    marc.enter_grade(97);

    classroom = {sally, john, marc};

    display_grades(classroom);

}