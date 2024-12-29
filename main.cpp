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
void notFoundMessage(int rollNo);

std::vector<Student> students;

int main()
{
    loadStudentsFromFile();
    int choice;

    do
    {
        // Clear screen for a fresh menu display (optional)
        std::cout << "\033[2J\033[1;1H"; // ANSI escape code for clearing screen

        std::cout << std::setw(35) << std::setfill('=') << "" << "\n";
        std::cout << std::setw(14) << std::setfill(' ') << "Student Management System" << "\n";
        std::cout << std::setw(35) << std::setfill('=') << "" << "\n\n";

        std::cout << "1. Add Student\n";
        std::cout << "2. View All Students\n";
        std::cout << "3. Search Student by ID\n";
        std::cout << "4. Update Student\n";
        std::cout << "5. Delete Student\n";
        std::cout << "6. Save to File\n";
        std::cout << "7. Exit\n";

        std::cout << "\nEnter your choice (1-7): ";
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
            std::cout << "\nThank you for using the Student Management System!\n";
            break;
        default:
            std::cout << "\nInvalid Choice, please try again.\n";
            break;
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore();
        std::cin.get();

    } while (choice != 7);

    return 0;
}

void addStudent()
{
    int age, rollNo;
    std::string name, course;
    float gpa;

    std::cout << "\n==============================\n";
    std::cout << "      Add New Student\n";
    std::cout << "==============================\n";

    std::cout << "\nEnter Roll Number: ";
    std::cin >> rollNo;

    for (const Student &student : students)
    {
        if (student.getRollNo() == rollNo)
        {
            std::cout << "Error: Roll Number " << rollNo << " already exists. Please enter a unique roll number.\n";
            return;
        }
    }

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

    std::cout << "\nStudent added successfully!\n";
    std::cout << "==============================\n";
}
void viewStudent()
{
    std::cout << "\n==============================\n";
    std::cout << "      View All Students\n";
    std::cout << "==============================\n";

    if (students.empty())
    {
        std::cout << "\nNo students found in the system.\n";
        return;
    }

    for (const Student &student : students)
    {
        student.displayDetails();
        std::cout << "\n------------------------------\n";
    }

    std::cout << "\n==============================\n";
}
void searchStudent()
{
    int rollNo;
    std::cout << "\n==============================\n";
    std::cout << "      Search Student\n";
    std::cout << "==============================\n";
    std::cout << "Enter Roll Number to search: ";
    std::cin >> rollNo;
    std::cin.ignore();

    for (const Student &student : students)
    {
        if (student.getRollNo() == rollNo)
        {
            std::cout << "\n==============================\n";
            std::cout << "    Student Found\n";
            std::cout << "==============================\n";
            student.displayDetails();
            std::cout << "\n==============================\n";
            return;
        }
    }
    notFoundMessage(rollNo);
}

void updateStudent()
{
    int rollNo;
    std::cout << "\n==============================\n";
    std::cout << "      Update Student Details\n";
    std::cout << "==============================\n";
    std::cout << "Enter Roll Number for the student whose details need to be updated: ";
    std::cin >> rollNo;
    std::cin.ignore();

    std::string name, course;
    float gpa;
    int age;
    std::cout << "\nEnter new details:\n";
    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Course: ";
    std::getline(std::cin, course);
    std::cout << "GPA: ";
    std::cin >> gpa;
    std::cout << "Age: ";
    std::cin >> age;
    std::cin.ignore();

    for (Student &student : students)
    {
        if (student.getRollNo() == rollNo)
        {
            student.setAge(age);
            student.setName(name);
            student.setCourse(course);
            student.setGPA(gpa);

            std::cout << "\n==============================\n";
            std::cout << "  Student Details Updated\n";
            std::cout << "==============================\n";
            student.displayDetails();
            std::cout << "\n==============================\n";
            return;
        }
    }
    notFoundMessage(rollNo);
}
void deleteStudent()
{
    int rollNo;
    std::cout << "\n==============================\n";
    std::cout << "       Remove Student\n";
    std::cout << "==============================\n";
    std::cout << "Enter Roll Number of the student to remove: ";
    std::cin >> rollNo;
    std::cin.ignore();

    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->getRollNo() == rollNo)
        {
            students.erase(it); // erase requires an iterator as an argument so it is an iterator meaning storing address for that instance
            std::cout << "\n==============================\n";
            std::cout << "   Student Removed Successfully\n";
            std::cout << "==============================\n";
            return;
        }
    }
    notFoundMessage(rollNo);
}
void saveToFile()
{
    json j;
    for (const Student &student : students)
    {
        j.push_back(student.toJson());
    }

    std::ofstream file(STUDENT_FILE); // ifstream is used when we want to read data from a file
    if (file.is_open())
    {
        file << j.dump(4);
        file.close();

        std::cout << "\n==============================\n";
        std::cout << "   Students Data Saved\n";
        std::cout << "   File: " << STUDENT_FILE << "\n";
        std::cout << "==============================\n";
    }
    else
    {
        std::cerr << "\nError: Unable to open file for writing!\n";
    }
}

void loadStudentsFromFile()
{
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

        std::cout << "\n==============================\n";
        std::cout << "   Student Data Loaded\n";
        std::cout << "   File: " << STUDENT_FILE << "\n";
        std::cout << "==============================\n";
    }
    else
    {
        std::cerr << "\nError: Unable to open file for reading!\n";
    }
}

void notFoundMessage(int rollNo)
{
    std::cout << "\nStudent with roll number " << rollNo << " not found.\n";
}