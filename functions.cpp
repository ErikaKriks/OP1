#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include "functions.h"


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



// Function to calculate the final mark for a student
float calculateFinalMarkAvg(const Student &student) {
    float sum = 0.0;

    if (student.marks.empty()) {
        return 0.6 * student.examMark; // If no individual marks, return 0.6 * exam mark
    }
    
    // Calculate the sum of individual marks
    for (int mark : student.marks) {
        sum += mark;
    }
    
    // Calculate the average of individual marks
    float averageMarks = sum / student.marks.size();
    
    // Calculate the final mark using the formula: 0.4 * average marks + 0.6 * exam
    return 0.4 * averageMarks + 0.6 * student.examMark;
}


// Function to calculate the final mark using median
float calculateFinalMarkMed(const Student &student) {
    if (student.marks.empty()) {
        return 0.6 * student.examMark; // If no individual marks, return 0.6 * exam mark
    }

    // Sort the individual marks
    vector<int> sortedMarks = student.marks;
    sort(sortedMarks.begin(), sortedMarks.end());
    
    int n = student.marks.size();

    // Calculate the median
    float median;
    if (n % 2 == 0) {
        // If even number of marks, take the average of the middle two
        int middle1 = sortedMarks[(n / 2) - 1];
        int middle2 = sortedMarks[n / 2];
        median = (static_cast<float>(middle1) + static_cast<float>(middle2)) / 2.0;
    } else {
        // If odd number of marks, take the middle value
        median = static_cast<float>(sortedMarks[n / 2]);
    }

    // Calculate the final mark using the formula: 0.4 * median + 0.6 * exam
    return 0.4 * median + 0.6 * student.examMark;
}

void printStudentTable(const vector<Student> &students)
{
    // Print the table header
    printf("%-20s%-20s%-20s%-20s\n", "Name", "Surname", "Final Mark (Avg.)", "Final Mark (Med.)");
    printf("-----------------------------------------------------------------------------\n");

    // Print student data in a table
    for (const Student &student : students)
    {
        printf("%-20s%-20s%-20.2f%-20.2f\n", student.name.c_str(), student.surname.c_str(), student.finalMarkAvg, student.finalMarkMed);
    }

    // Print the table footer
    printf("-----------------------------------------------------------------------------\n");
}


// Comparison function for sorting students by name and surname
bool compareStudents(const Student &student1, const Student &student2) {
    // Compare by name
    int nameComparison = student1.name.compare(student2.name);
    if (nameComparison != 0) {
        return nameComparison < 0;
    }
    
    // If names are equal, compare by surname
    return student1.surname.compare(student2.surname) < 0;
}

void readStudentsFromFile(const string &filename, vector<Student> &students)
{
    ifstream inputFile(filename);

    try {
        if (filename.empty())
        {
            throw invalid_argument("Error: File name not provided.");
        }

        if (!inputFile.is_open())
        {
            throw runtime_error("Error: Unable to open the file.");
        }

        string line;
        bool firstLine = true; // Skip the first line with headers
        int lineCount = 0;

        while (getline(inputFile, line))
        {
            ++lineCount;

            if (firstLine)
            {
                firstLine = false;
                continue; // Skip the header line
            }

            Student student;
            std::istringstream iss(line);
            string name, surname;
            int mark;

            iss >> student.name >> student.surname;

            while (iss >> mark)
            {
                student.marks.push_back(mark);
            }

            // Assign the last value in marks as the exam mark
            if (!student.marks.empty())
            {
                student.examMark = student.marks.back();
                student.marks.pop_back(); // Remove the last element from marks
            }

            if (iss.eof())
            {
                iss.clear();
                iss >> student.examMark;
            }

            students.push_back(student);
        }

        inputFile.close();
    } catch (const invalid_argument &e) {
        cerr << e.what() << endl;
        cout << "Data file not provided." << endl;
    } catch (const runtime_error &e) {
        cerr << e.what() << endl;
        cout << "Error in code." << e.what() << endl;
    }
}
