#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ofstream outFile("color.txt");

    if (!outFile) {
        cout << "ERROR! CANNOT OPEN color.txt FOR WRITING." << endl;
        return 1;
    }

    outFile << "RED" << endl;
    outFile << "BLUE" << endl;
    outFile << "GREEN" << endl;
    outFile << "YELLOW" << endl;
    outFile << "PURPLE" << endl;

    outFile.close();

    ifstream inFile("color.txt");

    if (!inFile) {
        cout << "ERROR! CANNOT OPEN color.txt FOR READING." << endl;
        return 1;
    }

    ofstream copyFile("color_copy.txt");

    if (!copyFile) {
        cout << "ERROR! CANNOT OPEN color.txt FOR WRITING." << endl;
        return 1;
    }

    string line;

    while (getline(inFile, line)) {
        copyFile << line << endl;
    }

    inFile.close();
    copyFile.close();

    cout << "SUCCES! color.txt HAS BEEN COPIED TO color_copy.txt." << endl;

    return 0;
}
