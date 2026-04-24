#include <iostream>
#include <fstream>
using namespace std;

int countPrimes() {
    int count = 0;
    int num;
    ifstream file("NUMS.TXT");

    while (file >> num) {
        bool isPrime = true;
        if (num < 2) isPrime = false;
        for (int i = 2; i * i <= num && isPrime; i++) {
            if (num % i == 0) isPrime = false;
        }
        if (isPrime) count++;
    }

    file.close();
    return count;
}

int main() {
    cout << "NUMBER OF PRIME NUMBERS: " << countPrimes() << endl;
    return 0;
}
