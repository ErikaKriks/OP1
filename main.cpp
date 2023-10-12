#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include "functions.h"
#include <chrono> // For measuring time


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::printf;
using std::sort;
using std::ifstream;
using std::cerr;
using std::invalid_argument;
using std::runtime_error;

// new additions

#include <random> // for random number generation
#include <ctime>  // for seeding the random number generator
#include <cstdlib>

using std::to_string;
using std::default_random_engine;
using std::uniform_int_distribution;

string generateRandomName(int studentNumber);
string generateRandomSurname(int studentNumber);
int generateRandomMark();
Student generateRandomStudent(int studentNumber, int numMarks);





int main(){

    int stud_nr = 10;

    for (int i = 1; i <= stud_nr; ++i) {
        Student randomStudent = generateRandomStudent(i, 5); // Generating a random student with 5 marks
        cout << "Student " << i << " Data:" << endl;
        cout << "Name: " << randomStudent.name << endl;
        cout << "Surname: " << randomStudent.surname << endl;
        cout << "Exam Mark: " << randomStudent.examMark << endl;
        cout << "Individual Marks: ";
        for (int mark : randomStudent.marks) {
            cout << mark << " ";
        }
        cout << endl << "--------------------------------" << endl;
    }

    return 0;

    // vector<Student> students;
    // string filename = "kursiokai.txt";

    // auto start = std::chrono::high_resolution_clock::now(); // Start measuring time

    // // Read student data from the file
    // readStudentsFromFile(filename, students);

    // auto end = std::chrono::high_resolution_clock::now(); // Stop measuring time
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // // Calculate Final Mark based on Average and Median of marks
    // for (size_t i = 0; i < students.size(); ++i)
    // {
    //     Student &student = students[i];
        
    //     // Calculate Final Mark based on Average
    //     student.finalMarkAvg = calculateFinalMarkAvg(student);

    //     // Calculate Final Mark based on Median
    //     student.finalMarkMed = calculateFinalMarkMed(student);
    // }

    // // Sort the students vector
    // sort(students.begin(), students.end(), compareStudents);

    // // Displaying a table of results
    // printStudentTable(students);

    // // For testing purposes
    // cout << "Total number of lines read: " << students.size() + 1 << " (including header)" << endl;
    // cout << "Time taken to read the file: " << duration.count() << " microseconds" << endl;

    // return 0;
        
}


// Function to generate a random student name
string generateRandomName(int studentNumber) {
    return "Vardas" + to_string(studentNumber);
}


// Function to generate a random student surname
string generateRandomSurname(int studentNumber) {
    return "Pavarde" + to_string(studentNumber);
}


// Function to generate random individual marks between 1 and 10
int generateRandomMark() {
    static default_random_engine generator(time(0));
    uniform_int_distribution<int> markDistribution(1, 10);
    return markDistribution(generator);
}


// Function to generate random student data
Student generateRandomStudent(int studentNumber, int numMarks) {
    Student student;
    student.name = generateRandomName(studentNumber);
    student.surname = generateRandomSurname(studentNumber);
    student.examMark = generateRandomMark(); // Random exam mark between 1 and 10

    for (int i = 0; i < numMarks; ++i) {
        student.marks.push_back(generateRandomMark()); // Random individual marks between 1 and 10
    }

    return student;
}