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




int main(){

    // vector<int> numStudentsList = {1000, 10000, 100000, 1000000, 10000000};
    vector<int> numStudentsList = {10};

    for (int numStudents : numStudentsList) {
        vector<Student> students;
        for (int i = 1; i <= numStudents; ++i) {
            students.push_back(generateRandomStudent(i, 15)); // 15 random individual marks
        }

        vector<Student> failStudents;
        vector<Student> passStudents;

        for (const Student& student : students) {
            float finalMark = calculateFinalMarkAvg(student); // You can use either Avg or Med function
            if (finalMark < 5.0) {
                failStudents.push_back(student);
            } else {
                passStudents.push_back(student);
            }
        }

        // Sort the failStudents and passStudents vectors
        sort(failStudents.begin(), failStudents.end(), compareStudents);
        sort(passStudents.begin(), passStudents.end(), compareStudents);


        string filenameFail = "students" + to_string(numStudents) + "_fail.txt";
        string filenamePass = "students" + to_string(numStudents) + "_pass.txt";

        saveStudentDataToFile(filenameFail, failStudents);
        saveStudentDataToFile(filenamePass, passStudents);

        cout << "Data for " << numStudents << " students has been saved to " << filenameFail << " and " << filenamePass << endl;
    }

    return 0;
        
}


