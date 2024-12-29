### **Student Management System**

The **Student Management System** is a console-based application designed to manage and organize student data efficiently. It allows users to perform various operations such as adding, viewing, updating, and deleting student records. The system supports storing student details, including their name, roll number, age, course, and GPA, and it allows for data persistence by saving and loading student information from a file.

#### **Key Features:**
1. **Add Student**: Users can input and store new student records, including personal details such as name, age, course, and GPA.
2. **View All Students**: Displays a list of all students currently in the system with their details formatted clearly for easy viewing.
3. **Search Student by ID**: Users can search for a specific student by their roll number and view their details.
4. **Update Student Information**: Allows the modification of an existing student's data, such as name, age, course, or GPA.
5. **Delete Student**: Students can be removed from the system using their roll number, ensuring the data stays up-to-date.
6. **Save to File**: All student data is saved to a file, ensuring persistence even after the program ends. The file can be loaded when the program is restarted.
7. **Load from File**: On program startup, the system loads previously saved student data from a file, making it easy to continue managing records across sessions.

#### **Data Structure and Functionality**:
- The system uses a vector of `Student` objects, each of which contains key attributes like `name`, `course`, `rollNo`, `age`, and `gpa`.
- Student records are serialized into JSON format for easy storage and retrieval from a file, making it simple to backup, share, or transport the data.

#### **User Interaction**:
- The system presents a simple text-based menu that is easy to navigate. 
- Users interact with the system by entering numeric choices corresponding to the available actions.
- Each operation (e.g., adding a student or updating details) is prompted by specific instructions for the user, and appropriate messages are displayed after each operation to confirm successful actions or errors.

#### **Persistence**:
- Student data is stored in a JSON file (`students.json`), which ensures that information is saved between sessions.
- The application reads from this file at the beginning of each session, loading the stored data to restore the list of students.

#### **Technologies Used**:
- **C++**: The application is written in C++, leveraging its powerful features such as object-oriented programming and standard library functions.
- **JSON for Modern C++ (nlohmann/json)**: This library is used to handle the serialization and deserialization of student data in JSON format, providing a simple and effective way to store and retrieve data from files.

#### **Example Use Cases**:
1. **Add a New Student**:
   - User inputs the student's roll number, name, course, age, and GPA.
   - The system stores this information and confirms the successful addition.

2. **View All Students**:
   - The system lists all stored students, displaying details like roll number, name, age, course, and GPA.

3. **Search for a Student by ID**:
   - Users can search by entering a roll number, and the system will display the details of the student if found.

4. **Update Student Details**:
   - If a user wants to correct or update a student's data, they can provide a roll number and modify any details like name, age, course, or GPA.

5. **Delete a Student**:
   - Users can remove a student from the system by entering their roll number.

6. **Saving Data**:
   - All the student data entered during the session can be saved to a file so that it can be loaded and accessed again in future sessions."