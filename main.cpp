#include <iostream>
#include <vector>
#include <fstream>
#include "Student.h"
#define STUDENT_FILE "students.json"

void addStudent();
void viewStudent();
void searchStudent();
void updateStudent();
void deleteStudent();
void saveToFile();
void loadStudentsFromFile();

std::vector<Student> students;

int main()
{
    loadStudentsFromFile();
    int choice;
    do
    {
        std::cout << "\nStudent Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. View All Students\n";
        std::cout << "3. Search Student by ID\n";
        std::cout << "4. Update Student\n";
        std::cout << "5. Delete Student\n";
        std::cout << "6. Save to File\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            viewStudent();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            updateStudent();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            saveToFile();
            break;
        case 7:
            std::cout << "Thank you for Student Management System!\n";
            break;
        default:
            std::cout << "Invalid Choice\n";
            break;
        }
    } while (choice != 7);
    return 0;
}

void addStudent()
{
    int age, rollNo;
    std::string name, course;
    float gpa;
    std::cout << "Enter Roll Number: ";
    std::cin >> rollNo;
    std::cin.ignore();
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Age: ";
    std::cin >> age;
    std::cin.ignore();
    std::cout << "Enter Course: ";
    std::getline(std::cin, course);
    std::cout << "Enter GPA: ";
    std::cin >> gpa;
    students.emplace_back(name, course, rollNo, age, gpa);
    std::cout << "Student added successfully!\n";
}
void viewStudent()
{
    std::cout << "\n################\n\n";
    if (students.empty())
    {
        std::cout << "No Student Found\n";
        std::cout << "\n################\n";
        return;
    }
    for (const Student &student : students)
    {
        student.displayDetails();
        std::cout << "\n";
    }
    std::cout << "################\n";
}
void searchStudent()
{
    std::cout << "\n################\n";
    int rollNo;
    std::cout << "Enter Student to search: ";
    std::cin >> rollNo;
    std::cin.ignore();
    for (const Student &student : students)
    {
        if (student.getRollNo() == rollNo)
        {
            std::cout << "\n################\n";
            student.displayDetails();
            std::cout << "\n################\n";
            return;
        }
    }
    std::cout << "Student with roll number " << rollNo << " not found.\n";
    std::cout << "\n################\n";
}

void updateStudent()
{
    std::cout << "\n################\n";
    int rollNo;
    std::cout << "Enter roll number for the student whose details needs to update: ";
    std::cin >> rollNo;
    std::cin.ignore();

    for (Student &student : students)
    {
        if (student.getRollNo() == rollNo)
        {
            std::string name, course;
            float gpa;
            int age;
            std::cout << "Enter Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter Course: ";
            std::getline(std::cin, course);
            std::cout << "Enter GPA: ";
            std::cin >> gpa;
            std::cout << "Enter Age: ";
            std::cin >> age;
            std::cin.ignore();
            student.setAge(age);
            student.setName(name);
            student.setCourse(course);
            student.setGPA(gpa);
            std::cout << "Student details updated successfully.\n";
            std::cout << "\n################\n";
            return;
        }
    }
    std::cout << "Student with roll number " << rollNo << " not found.\n";
    std::cout << "\n################\n";
}
void deleteStudent()
{
    std::cout << "\n################\n";
    int rollNo;
    std::cout << "Enter roll number of the student to remove: ";
    std::cin >> rollNo;
    std::cin.ignore();
    for (auto i = students.begin(); i != students.end(); i++)
    {
        if (i->getRollNo() == rollNo)
        {
            students.erase(i);
            std::cout << "Student with roll number " << rollNo << " removed successfully.\n";
            std::cout << "\n################\n";
            return;
        }
    }
    std::cout << "Student with roll number " << rollNo << " removed successfully.\n";
    std::cout << "\n################\n";
}
void saveToFile()
{
    std::cout << "\n################\n";
    json j;
    for (const Student &student : students)
    {
        j.push_back(student.toJson());
    }
    std::ofstream file(STUDENT_FILE); // ofstream is used when we want to write data in a file
    if (file.is_open())
    {
        file << j.dump(4);
        file.close();
        std::cout << "Students data saved to " << STUDENT_FILE << "\n";
    }
    else
    {
        std::cerr << "Error opening file for writing!\n";
    }
    std::cout << "\n################\n";
}

void loadStudentsFromFile()
{
    std::cout << "\n################\n";
    std::ifstream file(STUDENT_FILE); // ifstream is used when we want to read data from a file

    if (file.is_open())
    {
        json j;
        file >> j;
        for (const auto &item : j)
        {
            students.push_back(Student::fromJson(item));
        }
        file.close();
        std::cout << "Student data loaded from " << STUDENT_FILE << "\n";
    }
    else
    {
        std::cerr << "Error opening file for reading!\n";
    }
    std::cout << "\n################\n";
}