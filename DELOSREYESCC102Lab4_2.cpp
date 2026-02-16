#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

int main() {
    char runAgain;

    do {
        array<array<float, 4>, 5> sales{};
        int sp, prod;
        float amount;
        char choice;

        do {
            cout << "\nSALESPERSON(1-4): ";
            cin >> sp;
            while(sp < 1 || sp > 4){
                cout << "INVALID INPUT! ENTER SALESPERSON NUMBER (1-4): ";
                cin >> sp;
            }

            cout << "PRODUCT (1-5): ";
            cin >> prod;
            while(prod < 1 || prod > 5){
                cout << "INVALID INPUT! ENTER PRODUCT NUMBER(1-5): ";
                cin >> prod;
            }

            cout << "AMOUNT: $";
            cin >> amount;
            while(amount < 0){
                cout << "INVALID AMOUNT! ENTER POSITIVE VALUE: $";
                cin >> amount;
            }

            sales[prod-1][sp-1] += amount;

            cout << "ADD MORE? (y/n): ";
            cin >> choice;

        } while(choice == 'y' || choice == 'Y');

        cout << "\n---------------- MONTHLY SALES SUMMARY ----------------\n";
        cout << setw(10) << "PRODUCT"
             << setw(8) << "S1"
             << setw(8) << "S2"
             << setw(8) << "S3"
             << setw(8) << "S4"
             << setw(10) << "TOTAL" << endl;

        cout << "--------------------------------------------------------\n";

        float grandTotal = 0;

        for(int i = 0; i < 5; i++){
            float rowTotal = 0;
            cout << setw(10) << i+1;
            for(int j = 0; j < 4; j++){
                cout << setw(8) << fixed << setprecision(2) << sales[i][j];
                rowTotal += sales[i][j];
            }
            cout << setw(10) << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "--------------------------------------------------------\n";

        cout << setw(10) << "TOTAL";
        for(int j = 0; j < 4; j++){
            float colTotal = 0;
            for(int i = 0; i < 5; i++)
                colTotal += sales[i][j];
            cout << setw(8) << fixed << setprecision(2) << colTotal;
        }

        cout << setw(10) << grandTotal << endl;
        cout << "--------------------------------------------------------\n";

        cout << "DO YOU LIKE TO RUN AGAIN?: ";
        cin >> runAgain;

    } while(runAgain == 'y' || runAgain == 'Y');


    return 0;
}

