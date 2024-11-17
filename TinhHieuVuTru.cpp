#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false; 

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

string decodeMessage(int M) {
    vector<char> message;

    for (int i = 1; i <= M; ++i) {
        if (M % i == 0 && isPrime(i)) {
            char letter = 'A' + (i % 26);
            message.push_back(letter);
        }
    }
    sort(message.begin(), message.end());
    return string(message.begin(), message.end());
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int M;
    do {
        cin >> M;
    } while (M <= 2 || M >= 10000000000000);
    string result = decodeMessage(M);
    cout << result << endl;

    return 0;
}