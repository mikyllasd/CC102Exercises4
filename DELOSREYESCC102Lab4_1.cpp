#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

int main() {
    char choice;

    do {
        int students, quizzes;

        cout << "ENTER NUMBER OF STUDENTS: ";
        cin >> students;

        cout << "ENTER NUMBER OF QUIZZES: ";
        cin >> quizzes;


        array<array<int,20>,20> scores{};
        array<float,20> average{};

        for(int i=0; i<students; i++) {
            int sum = 0;

            cout << "\nENTER SCORES OF STUDENT " << i+1 << ":\n";
            for(int j=0; j<quizzes; j++) {
                cout << "QUIZ " << j+1 << ": ";
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            average[i] = (float)sum / quizzes;
        }

        cout << "\n----------------------------------------------\n";
        cout << setw(12) << "STUDENTS";

        for(int q=0; q<quizzes; q++) {
            cout << setw(8) << ("Q" + to_string(q+1));
        }

        cout << setw(10) << "AVERAGE\n";
        cout << "----------------------------------------------\n";

        for(int i=0; i<students; i++) {
            cout << setw(12) << ("STUDENT " + to_string(i+1));

            for(int j=0; j<quizzes; j++) {
                cout << setw(8) << scores[i][j];
            }

            cout << setw(10) << fixed << setprecision(2) << average[i] << endl;
        }

        cout << "----------------------------------------------\n";

        cout << "\nDO YOU WANT TO RUN AGAIN?: ";
        cin >> choice;

    } while(choice=='y' || choice=='Y');

    return 0;
}
