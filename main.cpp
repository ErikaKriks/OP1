#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;



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

int main(){
    int k; /**< Nunber of students in the class. */
    cout << "Number of students:" << endl;
    cin >> k;
    
    for (int i = 0; i < k; i ++){
        
        Student student;

        getInput(student);

        // Print the student's information
        cout << "Student Information:" << endl;
        cout << "Name: " << student.name << " " << student.surname << endl;
        cout << "Number of Marks: " << student.n << endl;
        cout << "Exam Mark: " << student.egz << endl;
        cout << "Individual Marks: ";
        for (size_t i = 0; i < student.marks.size(); ++i) {
        int mark = student.marks[i];
        cout << mark << " ";
        }
    
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