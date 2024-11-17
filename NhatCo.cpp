#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n, m;
        cin >> n >> m;
        char result = (n % (m + 1) == 0) ? 'A' : 'B';
        cout << result;
    }
    return 0;
}
