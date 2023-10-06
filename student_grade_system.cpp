// a system where you can input student’s grades, calculate the average, and determine the grade, the system should be able to accept user input

#include<iostream>
#include<iomanip>
using namespace std;

struct Student {
    string name;
    int numSubjects;
    int* marks;
};

int main() {
    Student student;

    cout << "Enter student's name: ";
    cin >> student.name;

    cout << "Enter number of subjects: ";
    cin >> student.numSubjects;

    student.marks = new int[student.numSubjects];

    for(int i = 0; i < student.numSubjects; i++) {
        cout << "Enter marks for subject " << i+1 << ": ";
        cin >> student.marks[i];
    }

    int total = 0;
    for(int i = 0; i < student.numSubjects; i++) {
        total += student.marks[i];
    }
    
    float average = (float)total / student.numSubjects;

    cout << "\n\n";
    cout << setw(10) << "Name" << setw(10) << "Total" << setw(10) << "Average" << "\n";
    cout << setw(10) << student.name << setw(10) << total << setw(10) << average << "\n";

    delete [] student.marks;

    return 0;
}
