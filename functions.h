#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <string>
#include <vector>

using std::string;
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
void printStudentTable(const vector<Student> &students);
void readStudentsFromFile(const string &filename, vector<Student> &students);
string generateRandomName(int studentNumber);
string generateRandomSurname(int studentNumber);
int generateRandomMark();
Student generateRandomStudent(int studentNumber, int numMarks);
void saveStudentDataToFile(const string& filename, const vector<Student>& students);
bool fileExists(const string& filename);
void generateStudentDataToFile(const string& filename, int numStudents, int numMarks);
int getUserSortOption();
bool compareByName(const Student &student1, const Student &student2);
bool compareBySurname(const Student &student1, const Student &student2);
bool compareByFinalMarkAvg(const Student &student1, const Student &student2);
bool compareByFinalMarkMedian(const Student &student1, const Student &student2);
void compareStudents(vector<Student> &students, int sortBy);


#endif // FUNCTIONS_H_INCLUDED