#include<iostream>
#include<string>
using namespace std;

struct book {
    int barcode;
    string title;
    int year;
    int rating;
};

string getCategory(int rating){
    if(rating == 5)      return "EXCELLENT";
    else if(rating == 4) return "VERY GOOD";
    else if(rating == 3) return "GOOD";
    else if(rating == 2) return "FAIR";
    else if(rating == 1) return "POOR";
    else                 return "NO RATING";
}

void input(book books[], int numBooks){
    for(int i=0; i<numBooks; i++){
        cout << "\n--- BOOK " << i+1 << " ---\n";

        int barcode;
        bool duplicate;
        do {
            duplicate = false;
            cout << "BARCODE:        ";
            cin >> barcode;

            for(int k=0; k<i; k++){
                if(books[k].barcode == barcode){
                    cout << "BARCODE ALREADY EXISTS! ENTER ANOTHER.\n";
                    duplicate = true;
                    break;
                }
            }
        } while(duplicate);

        books[i].barcode = barcode;

        cout << "TITLE:          ";
        cin.ignore();
        getline(cin, books[i].title);

        cout << "YEAR PUBLISHED: ";
        cin >> books[i].year;

        do {
            cout << "RATING (0-5):   ";
            cin >> books[i].rating;
            if(books[i].rating < 0 || books[i].rating > 5)
                cout << "INVALID! ENTER 0-5 ONLY.\n";
        } while(books[i].rating < 0 || books[i].rating > 5);
    }
}

void display(book books[], int numBooks){
    cout << "\n============================================================\n";
    cout << "BARCODE\tTITLE\t\t\tYEAR\tRATING\tCATEGORY\n";
    cout << "============================================================\n";

    for(int i=0; i<numBooks; i++){
        cout << books[i].barcode          << "\t"
             << books[i].title            << "\t\t\t"
             << books[i].year             << "\t"
             << books[i].rating           << "\t"
             << getCategory(books[i].rating) << "\n";
    }

    cout << "============================================================\n";
}

int main(){
    char runAgain;

    do {
        system("cls");
        int numBooks;
        cout << "ENTER NUMBER OF BOOKS: ";
        cin >> numBooks;

        book books[numBooks];

        input(books, numBooks);
        display(books, numBooks);

        cout << "\nRUN AGAIN? (y/n): ";
        cin >> runAgain;

    } while(runAgain == 'y' || runAgain == 'Y');

    cout << "\nDAGHANG SALAMAT!" << endl;
    return 0;
}
