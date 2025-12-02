#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;


char calculateGrade(int score) {
    if (score >= 90 && score <= 100) {
        return 'A';
    }
    else if (score >= 80) { // 80 - 89
        return 'B';
    }
    else if (score >= 70) { // 70 - 79
        return 'C';
    }
    else if (score >= 60) { // 60 - 69
        return 'D';
    }
    else { // น้อยกว่า 60
        return 'F';
    }
}

int main() {

    string studentID;
    string studentName;
    int score;


    cout << "Enter student ID: ";
    getline(cin, studentID);

    cout << "Enter student name: ";
    getline(cin, studentName);

    cout << "Enter score: ";
    cin >> score;


    if (score < 0 || score > 100) {
        cerr << "\nError: Score must be between 0 and 100." << endl;
        return 1;
    }


    char grade = calculateGrade(score);


    cout << "\n------ Student Report ------" << endl;


    cout << left << setw(13) << "Student ID" << ": " << studentID << endl;
    cout << left << setw(13) << "Name" << ": " << studentName << endl;

    cout << endl;

    cout << left << setw(13) << "Score" << ": " << score << endl;
    cout << left << setw(13) << "Grade" << ": " << grade << endl;
    cout << "-----------------------------" << endl;

    return 0;
}