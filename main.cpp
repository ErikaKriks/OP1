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
float calculateFinalMarkAvg(const Student &student);
float calculateFinalMarkMed(const Student &student);
void printStudentTable(const vector<Student> &students);



int main(){
    
    int k;
    cout << "Number of students:" << endl;
    cin >> k;

    vector<Student> students;

    for (int i = 0; i < k; i++)
    {
        Student student;
        getInput(student);
        // Calculate Final Mark based on Median
        // student.r = calculateFinalMarkMed(student);

        // Calculate Final Mark based on Average
        student.r = calculateFinalMarkAvg(student);
        
        students.push_back(student);
    }

    printStudentTable(students);
        
}


// Function to get input for a Student structure
void getInput(Student &student) {
    cout << "Enter the student's first name: " << endl;
    cin >> student.name;
    
    cout << "Enter the student's last name: " << endl;
    cin >> student.surname;

    cout << "Enter the exam mark the student has: " << endl;
    cin >> student.egz;

    int mark;
    cout << "Enter homework marks (press Enter twice to finish): ";

    while (true) {
        if (cin >> mark) {
            student.marks.push_back(mark); // Add the homework mark to the vector
        } else {
            // If the input is not numeric, clear the error state and ignore the input
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        char nextChar = cin.peek(); // Peek at the next character in input

        if (nextChar == '\n') {
            char enter = cin.get(); // Consume the Enter character
            nextChar = cin.peek(); // Peek again

            if (nextChar == '\n') {
                break; // Exit the loop if double Enter is detected
            }
        }
    }

}


// Function to calculate the final mark for a student
float calculateFinalMarkAvg(const Student &student) {
    float sum = 0.0;
    
    // Calculate the sum of individual marks
    for (int mark : student.marks) {
        sum += mark;
    }
    
    // Calculate the average of individual marks
    float averageMarks = sum / student.marks.size();
    
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
    return 0.4 * median + 0.6 * student.egz;
}

void printStudentTable(const vector<Student> &students)
{
    // Print the table header
    printf("%-20s%-20s%-40s\n", "Name", "Surname", "Final Mark (Avg.)/ Final Mark (Med.)");
    printf("-----------------------------------------------------------------------------\n");

    // Print student data in a table
    for (const Student &student : students)
    {
        printf("%-20s%-20s%-10.2f\n", student.name.c_str(), student.surname.c_str(), student.r);
    }

    // Print the table footer
    printf("-----------------------------------------------------------------------------\n");
}

