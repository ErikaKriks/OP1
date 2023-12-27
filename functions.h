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
    float finalMarkMed; /**< The median score of the student. */
    float finalMark; /**< The score of the student. */
};

// Functions
int usersChoice();
int usersChoiceAvgMed();
int usersChoiceVectorList();
int usersChoiceStrategy();
int getUserSortOption();
void getInput(Student &student);
void getInputAuto(Student &student);
float calculateFinalMarkAvg(const Student &student);
float calculateFinalMarkMed(const Student &student);
void printStudentTable(const vector<Student> &students);
void printStudentTableAvgMed(const vector<Student> &students);
void readStudentsFromFileVector(const string &filename, vector<Student> &students);
void readStudentsFromFileList(const string &filename, list<Student> &students);
bool compareStudentsSimple(const Student &student1, const Student &student2); // old version
void compareStudentsList(list<Student>& students, int sortBy);
void compareStudents(vector<Student> &students, int sortBy); // for vector structure
bool compareByName(const Student &student1, const Student &student2);
bool compareBySurname(const Student &student1, const Student &student2);
bool compareByFinalMarkAvg(const Student &student1, const Student &student2);
bool compareByFinalMarkMedian(const Student &student1, const Student &student2);
string generateRandomName(int studentNumber);
string generateRandomSurname(int studentNumber);
int generateRandomMark();
// Student generateRandomStudent(int studentNumber, int numMarks);
// void saveStudentDataToFileList(const string& filename, const list<Student>& students);
// void saveStudentDataToFileVector(const string& filename, const vector<Student>& students);
void saveStudentDataToFileList(const string &filename, const list<Student> &students);
void saveStudentDataToFile(const string& filename, const vector<Student>& students);
bool fileExists(const string& filename);
void generateStudentDataToFile(const string& filename, int numStudents, int numMarks);



#endif // FUNCTIONS_H_INCLUDED