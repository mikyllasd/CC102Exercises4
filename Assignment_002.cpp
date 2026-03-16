#include<iostream>
using namespace std;

void analyzeGrades(int* grades, int students, int subjects){

    cout << "\n=============== GRADE MATRIX ===============\n";
    cout << "\t";
    for(int j=0; j<subjects; j++)
        cout << "SUB" << j+1 << "\t";
    cout << "AVERAGE";
    cout << "\n";

    for(int i=0; i<students; i++){
        cout << "S" << i+1 << "\t";
        int sum = 0;
        for(int j=0; j<subjects; j++){
            cout << *(grades + i*subjects + j) << "\t";
            sum += *(grades + i*subjects + j);
        }
        double avg = (double)sum / subjects;
        cout << avg;
        cout << "\n";
    }

    int highest = *(grades);
    for(int i=0; i<students; i++)
        for(int j=0; j<subjects; j++)
            if(*(grades + i*subjects + j) > highest)
                highest = *(grades + i*subjects + j);

    cout << "\nHIGHEST GRADE: " << highest << endl;
}

int main(){
    int students, subjects;
    cout << "ENTER NUMBER OF STUDENTS: ";
    cin >> students;
    cout << "ENTER NUMBER OF SUBJECTS: ";
    cin >> subjects;

    int grades[students][subjects];

    for(int i=0; i<students; i++)
        for(int j=0; j<subjects; j++){
            cout << "STUDENT " << i+1 << " SUBJECT " << j+1 << ": ";
            cin >> grades[i][j];
        }

    analyzeGrades(&grades[0][0], students, subjects);

    return 0;
}
