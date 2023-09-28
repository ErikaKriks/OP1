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


int main(){
    vector<Student> students;
    string filename = "kursiokai.txt";

    auto start = std::chrono::high_resolution_clock::now(); // Start measuring time

    // Read student data from the file
    readStudentsFromFile(filename, students);

    auto end = std::chrono::high_resolution_clock::now(); // Stop measuring time
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Calculate Final Mark based on Average and Median of marks
    for (size_t i = 0; i < students.size(); ++i)
    {
        Student &student = students[i];

        // Calculate Final Mark based on Average
        student.finalMarkAvg = calculateFinalMarkAvg(student);

        // Calculate Final Mark based on Median
        student.finalMarkMed = calculateFinalMarkMed(student);
    }

    // Sort the students vector
    sort(students.begin(), students.end(), compareStudents);

    // Displaying a table of results
    printStudentTable(students);

    // For testing purposes
    cout << "Total number of lines read: " << students.size() + 1 << " (including header)" << endl;
    cout << "Time taken to read the file: " << duration.count() << " microseconds" << endl;

    return 0;
        
}
