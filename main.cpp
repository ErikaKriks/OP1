#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <random> // for random number generation
#include <ctime>  // for seeding the random number generator
#include <cstdlib>
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
using std::to_string;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::ofstream;
using std::left;
using std::setw;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::seconds;




int main() {
    vector<int> numStudentsList = {1000, 10000, 100000, 1000000, 10000000};
    // vector<int> numStudentsList = {10, 100}; // For testing purposes
    int numMarks = 15;
    int sortOption = 0;
    sortOption = getUserSortOption();

    // Checking if students file already exists
    for (int numStudents : numStudentsList) {
        string filename = "students" + to_string(numStudents) + ".txt";
        if (fileExists(filename)) {
            cout << filename << " exists! Experiment will be conducted." << endl;
        } 
        else {
            cout << filename << " will be generated." << endl;
            
            // Data generation and saving
            auto startGeneration = std::chrono::high_resolution_clock::now();
            generateStudentDataToFile(filename, numStudents, numMarks);
            auto endGeneration = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> generationTime = endGeneration - startGeneration;

            cout << "Execution times for " << numStudents << " students:" << endl;
            cout << "Data generation and saving: " << generationTime.count() << " seconds" << endl;
        }
    }
    cout << "------------------------" << endl;

    for (int numStudents : numStudentsList) {
        
        string filename = "students" + to_string(numStudents) + ".txt";
        
        // Reading data
        auto startReading = std::chrono::high_resolution_clock::now();
        vector<Student> readStudents;
        readStudentsFromFile(filename, readStudents);
        auto endReading = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> categorizationTime = endReading - startReading;
        

        // Categorization
        auto startCategorization = std::chrono::high_resolution_clock::now();
        vector<Student> failStudents;
        vector<Student> passStudents;

        for (Student& student : readStudents) {
            student.finalMarkAvg = calculateFinalMarkAvg(student); // Final mark can be generated using Avg or Med
            student.finalMarkMed = calculateFinalMarkMed(student);
            if (student.finalMarkAvg < 5.0) {
                failStudents.push_back(student);
            } else {
                passStudents.push_back(student);
            }
        }

        // Sort the failStudents and passStudents vectors
        compareStudents(failStudents, sortOption);
        compareStudents(passStudents, sortOption);
        auto endCategorization = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> readingTime = endCategorization - startCategorization;

        // Saving categorized data
        auto startSavingCategorized = std::chrono::high_resolution_clock::now();
        string filenameFail = "students" + to_string(numStudents) + "_fail.txt";
        string filenamePass = "students" + to_string(numStudents) + "_pass.txt";

        saveStudentDataToFile(filenameFail, failStudents);
        saveStudentDataToFile(filenamePass, passStudents);
        auto endSavingCategorized = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> savingCategorizedTime = endSavingCategorized - startSavingCategorized;

        cout << "Execution times for " << numStudents << " students:" << endl;
        cout << "Reading: " << readingTime.count() << " seconds" << endl;
        cout << "Categorization: " << categorizationTime.count() << " seconds" << endl;
        cout << "Saving categorized data: " << savingCategorizedTime.count() << " seconds" << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}

