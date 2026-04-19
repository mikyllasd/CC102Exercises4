#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    ofstream outFile("original.txt");

    if (!outFile) {
        cout << "ERROR! CANNOT OPEN original.txt FOR WRITING." << endl;
        return 1;
    }

    outFile << "ONE" << endl;
    outFile << "TWO" << endl;
    outFile << "THREE" << endl;
    outFile << "FOUR" << endl;
    outFile << "FIVE" << endl;
    outFile << "SIX" << endl;

    outFile.close();

    ifstream inFile("original.txt");

    if (!inFile) {
        cout << "ERROR! CANNOT OPEN original.txt FOR READING." << endl;
        return 1;
    }

    vector<string> words;
    string line;

    while (getline(inFile, line)) {
        words.push_back(line);
    }

    inFile.close();

    sort(words.begin(), words.end());

    ofstream sortedFile("sorted.txt");

    if (!sortedFile) {
        cout << "ERROR! CANNOT OPEN sorted.txt FOR WRITING." << endl;
        return 1;
    }

    for (int i = 0; i < words.size(); i++) {
        sortedFile << words[i] << endl;
    }

    sortedFile.close();

    cout << "SUCCESS! sorted.txt HAS BEEN CREATED." << endl;

    return 0;
}
