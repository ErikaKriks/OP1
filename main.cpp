#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw; /*ar reikia?*/
using std::printf;
using std::sort;



/**
 * @struct Student
 *
 * @brief Represents a student with their name, surname, marks, and a rating.
 */
struct Student
{
    string name; /**< The first name of the student. */
    string surname; /**< The last name of the student. */
    int n, egz; /**< The number of marks the student has. The mark of exam.*/
    vector<int> marks; /**< A vector storing the student's individual marks. */
    float r; /**< The average score of the student. */
};


// Function to get input for a Student structure
void getInput(Student &student);
float calculateFinalMark(const Student &student);
float calculateFinalMarkMed(const Student &student);



int main(){
    int k; /**< Nunber of students in the class. */
    cout << "Number of students:" << endl;
    cin >> k;
    
    for (int i = 0; i < k; i ++){
        
        Student student;

        getInput(student);

        // Calculate Final Mark based on Averge or Median of marks
        // student.r = calculateFinalMark(student);
        student.r = calculateFinalMarkMed(student);


        // Print the table header
        printf("%20c%20s%20c\n\n", ' ', "Students' Information", ' ');
        printf("%-20s%-20s%-40s\n", "Name", "Surname", "Final Mark (Avg.)/ Final Mark (Med.)");
        printf("-----------------------------------------------------------------------------\n");
        // Print the data for a student in a row
        printf("%-20s%-20s%-440.2f\n", student.name.c_str(), student.surname.c_str(), student.r);

        // Print the table footer
        printf("-----------------------------------------------------------------------------\n");

        
}


}

// Function to get input for a Student structure
void getInput(Student &student) {
    cout << "Enter the student's first name: " << endl;
    cin >> student.name;
    
    cout << "Enter the student's last name: " << endl;
    cin >> student.surname;

    cout << "Enter the number of marks the student has: " << endl;
    cin >> student.n;
    
    cout << "Enter the student's individual marks separated by spaces: " << endl;
    student.marks.clear(); // Clear any existing marks
    for (int i = 0; i < student.n; ++i) {
        int mark;
        cin >> mark;
        student.marks.push_back(mark);
    }

    cout << "Enter the exam mark the student has: " << endl;
    cin >> student.egz;
}

// Function to calculate the final mark for a student
float calculateFinalMark(const Student &student) {
    float sum = 0.0;
    
    // Calculate the sum of individual marks
    for (int mark : student.marks) {
        sum += mark;
    }
    
    // Calculate the average of individual marks
    float averageMarks = sum / student.n;
    
    // Calculate the final mark using the formula: 0.4 * average marks + 0.6 * exam
    return 0.4 * averageMarks + 0.6 * student.egz;
}

// Function to calculate the final mark using median
float calculateFinalMarkMed(const Student &student) {
    if (student.marks.empty()) {
        return 0.6 * student.egz; // If no individual marks, return 0.6 * exam mark
    }

    // Sort the individual marks
    vector<int> sortedMarks = student.marks;
    sort(sortedMarks.begin(), sortedMarks.end());

    // Calculate the median
    float median;
    if (student.n % 2 == 0) {
        // If even number of marks, take the average of the middle two
        int middle1 = sortedMarks[(student.n / 2) - 1];
        int middle2 = sortedMarks[student.n / 2];
        median = (static_cast<float>(middle1) + static_cast<float>(middle2)) / 2.0;
    } else {
        // If odd number of marks, take the middle value
        median = static_cast<float>(sortedMarks[student.n / 2]);
    }

    // Calculate the final mark using the formula: 0.4 * median + 0.6 * exam
    return 0.4 * median + 0.6 * student.egz;
}

