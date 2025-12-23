#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void displayStudentInfo(string name, string id, double score, char grade)
{
    cout << "Student Name: " << name << "\n";
    cout << "Student ID  : " << id << "\n";
    cout << "Score       : " << fixed << setprecision(2) << score << "\n";
    cout << "Grade       : " << grade << "\n";
}

void calculateGrade(double score, char& grade)
{
    if (score >= 90) grade = 'A';
    else if (score >= 80) grade = 'B';
    else if (score >= 70) grade = 'C';
    else if (score >= 60) grade = 'D';
    else grade = 'F';
}

int main()
{
    const int N = 3; // students
    const int M = 4; // subjects

    string name[N], id[N];
    double score[N][M];
    double total[N];
    char grade[N];

    // Initialize totals
    for (int i = 0; i < N; ++i) total[i] = 0.0;

    // Input name/id and M scores per student
    for (int i = 0; i < N; ++i) {
        cout << "Enter student " << (i + 1) << " name: ";
        getline(cin >> ws, name[i]); // read full line (handles leading newline)

        cout << "Enter student " << (i + 1) << " id: ";
        cin >> id[i];

        for (int j = 0; j < M; ++j) {
            cout << "Enter student " << (i + 1) << " score" << (j + 1) << ": ";
            cin >> score[i][j];
            total[i] += score[i][j];
        }
        cout << "\n";
    }

    // Calculate grade from total and display each student
    for (int i = 0; i < N; ++i) {
        calculateGrade(total[i], grade[i]);
        cout << "Student " << (i + 1) << " Information:\n";
        displayStudentInfo(name[i], id[i], total[i], grade[i]);
        if (i + 1 < N) cout << "\n";
    }

    return 0;
}
