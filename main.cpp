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
#include <list> 



using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;
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
    // vector<int> numStudentsList = {1000, 10000, 100000, 1000000, 10000000};
    vector<int> numStudentsList = {10, 100}; // For testing purposes


    for (int numStudents : numStudentsList) {
        // Data generation and saving
        auto startGeneration = std::chrono::high_resolution_clock::now();
        list<Student> students;
        for (int i = 1; i <= numStudents; ++i) {
            students.push_back(generateRandomStudent(i, 15)); // 15 random individual marks
        }
        string filename = "students" + to_string(numStudents) + ".txt";
        saveStudentDataToFile(filename, students);
        auto endGeneration = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> generationTime = endGeneration - startGeneration;

        // Reading data
        auto startReading = std::chrono::high_resolution_clock::now();
        list<Student> readStudents;
        readStudentsFromFile(filename, readStudents);
        auto endReading = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> categorizationTime = endReading - startReading;
        

        // Categorization
        auto startCategorization = std::chrono::high_resolution_clock::now();
        list<Student> failStudents;
        list<Student> passStudents;

        for (const Student& student : readStudents) {
            float finalMark = calculateFinalMarkAvg(student); // You can use either Avg or Med function
            if (finalMark < 5.0) {
                failStudents.push_back(student);
            } else {
                passStudents.push_back(student);
            }
        }

        // Sort the failStudents and passStudents lists
        sort(failStudents.begin(), failStudents.end(), compareStudents);
        sort(passStudents.begin(), passStudents.end(), compareStudents);
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
        cout << "Data generation and saving: " << generationTime.count() << " seconds" << endl;
        cout << "Reading: " << readingTime.count() << " seconds" << endl;
        cout << "Categorization: " << categorizationTime.count() << " seconds" << endl;
        cout << "Saving categorized data: " << savingCategorizedTime.count() << " seconds" << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}

