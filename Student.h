#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "libs/json.hpp"

using json = nlohmann::json;

class Student
{
private:
    std::string name, course;
    int rollNo, age;
    float gpa;

public:
    Student(std::string name, std::string course, int rollno, int age, float gpa);

    void setRollNo(int rollNo);
    void setAge(int age);
    void setGPA(float gpa);
    void setName(std::string name);
    void setCourse(std::string course);

    std::string getCourse() const;
    std::string getName() const;
    float getGPA() const;
    int getAge() const;
    int getRollNo() const;

    void displayDetails() const;

    json toJson() const;

    static Student fromJson(const json &j);
    
};

#endif