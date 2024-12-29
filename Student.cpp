#include <iostream>
#include <iomanip>
#include "Student.h"
#include "libs/json.hpp"

using json = nlohmann::json;

Student::Student(std::string name, std::string course, int rollNo, int age, float gpa) : name(name), course(course), rollNo(rollNo), age(age), gpa(gpa) {}

void Student::setRollNo(int rollNo)
{
    this->rollNo = rollNo;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setGPA(float gpa)
{
    this->gpa = gpa;
}

void Student::setName(std::string name)
{
    this->name = name;
}
void Student::setCourse(std::string course)
{
    this->course = course;
}

std::string Student::getCourse() const
{
    return course;
}
std::string Student::getName() const
{
    return name;
}

float Student::getGPA() const
{
    return gpa;
}

int Student::getAge() const
{
    return age;
}

int Student::getRollNo() const
{
    return rollNo;
}

void Student::displayDetails() const
{
    std::cout << "Name: " << name << "\n"
              << "Course: " << course << "\n"
              << "Roll Number: " << rollNo << "\n"
              << "Age: " << age << "\n"
              << "GPA: " << gpa << "\n";
}

json Student::toJson() const
{
    float roundedGpa = std::round(gpa * 100.0f) / 100.0f;
    return json{
        {"rollNo", rollNo},
        {"name", name},
        {"age", age},
        {"course", course},
        {"gpa", roundedGpa}};
}

Student Student::fromJson(const json &j)
{
    return Student(
        j.at("name").get<std::string>(),
        j.at("course").get<std::string>(),
        j.at("rollNo").get<int>(),
        j.at("age").get<int>(),
        j.at("gpa").get<float>());
}