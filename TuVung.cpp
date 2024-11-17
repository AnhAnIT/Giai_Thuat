#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}


long long countValidSubstrings(const string& s) {
    long long count = 0;
    long long vowelCount = 0, consonantCount = 0;

    for (char c : s) {
        if (isVowel(c)) {
            count += consonantCount;
            vowelCount++;
        }
        else {
            count += vowelCount;
            consonantCount++;
        }
    }

    return count;
}

int main() {

    ifstream inputFile("cau4.inp");
    ofstream outputFile("cau4.out");

    string s;
    inputFile >> s;


    long long result = countValidSubstrings(s);

  
    outputFile << result << endl;

    return 0;
}
