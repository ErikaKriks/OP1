#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random> // for random number generation
#include <ctime>  // for seeding the random number generator
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::printf;
using std::sort;
using std::default_random_engine;
using std::uniform_int_distribution;

struct Student
{
    string name;
    string surname;
    int n, egz;
    vector<int> marks;
    float r;
};

void getInput(Student &student);
float calculateFinalMarkAvg(const Student &student);
float calculateFinalMarkMed(const Student &student);
void printStudentTable(const vector<Student> &students);
int generateRandomMark(); // Function to generate a random mark

int main()
{
    int k;
    cout << "Number of students:" << endl;
    cin >> k;

    vector<Student> students;
    default_random_engine generator(time(0)); // Seed the random number generator

    for (int i = 0; i < k; i++)
    {
        Student student;
        getInput(student);

        // Calculate Final Mark based on Average
        student.r = calculateFinalMarkAvg(student);

        students.push_back(student);
    }

    printStudentTable(students);

    return 0;
}

void getInput(Student &student)
{
    cout << "Enter the student's first name: " << endl;
    cin >> student.name;

    cout << "Enter the student's last name: " << endl;
    cin >> student.surname;

    // Generate random exam mark (between 1 and 10)
    default_random_engine generator(time(0)); // Re-seed the random number generator
    uniform_int_distribution<int> examDistribution(1, 10);
    student.egz = examDistribution(generator);

    cout << "Enter the number of homework marks for the student: " << endl;
    cin >> student.n;

    // Generate random homework marks (between 1 and 10)
    for (int j = 0; j < student.n; j++)
    {
        student.marks.push_back(generateRandomMark());
    }
}

float calculateFinalMarkAvg(const Student &student)
{
    float sum = 0.0;

    for (int mark : student.marks)
    {
        sum += mark;
    }

    float averageMarks = sum / student.marks.size();

    return 0.4 * averageMarks + 0.6 * student.egz;
}

float calculateFinalMarkMed(const Student &student)
{
    if (student.marks.empty())
    {
        return 0.6 * student.egz;
    }

    vector<int> sortedMarks = student.marks;
    sort(sortedMarks.begin(), sortedMarks.end());

    int n = student.marks.size();
    float median;

    if (n % 2 == 0)
    {
        int middle1 = sortedMarks[(n / 2) - 1];
        int middle2 = sortedMarks[n / 2];
        median = (static_cast<float>(middle1) + static_cast<float>(middle2)) / 2.0;
    }
    else
    {
        median = static_cast<float>(sortedMarks[n / 2]);
    }

    return 0.4 * median + 0.6 * student.egz;
}

void printStudentTable(const vector<Student> &students)
{
    printf("%-20s%-20s%-40s\n", "Name", "Surname", "Final Mark (Avg.)/ Final Mark (Med.)");
    printf("-----------------------------------------------------------------------------\n");

    for (const Student &student : students)
    {
        printf("%-20s%-20s%-10.2f\n", student.name.c_str(), student.surname.c_str(), student.r);
    }

    printf("-----------------------------------------------------------------------------\n");
}

int generateRandomMark()
{
    // Generate random mark between 1 and 10
    default_random_engine generator(time(0));
    uniform_int_distribution<int> markDistribution(1, 10);
    return markDistribution(generator);
}
