#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <string>
#include <list>
#include <vector>

using std::string;
using std::list;
using std::vector;


// @struct Student
// @brief Represents a student with their name, surname, marks, and a rating.
struct Student
{
    string name; /**< The first name of the student. */
    string surname; /**< The last name of the student. */
    int examMark; /**< The number of marks the student has. The mark of exam.*/
    vector<int> marks; /**< A vector storing the student's individual marks. */
    float finalMarkAvg; /**< The average score of the student. */
    float finalMarkMed; /**< The average score of the student. */
};

// Functions
float calculateFinalMarkAvg(const Student &student);
float calculateFinalMarkMed(const Student &student);
void printStudentTable(const list<Student> &students);
void readStudentsFromFile(const string &filename, list<Student> &students);
bool compareStudents(const Student &student1, const Student &student2);
string generateRandomName(int studentNumber);
string generateRandomSurname(int studentNumber);
int generateRandomMark();
Student generateRandomStudent(int studentNumber, int numMarks);
void saveStudentDataToFile(const string& filename, const list<Student>& students);


#endif // FUNCTIONS_H_INCLUDED