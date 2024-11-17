#include <iostream>
using namespace std;

pair<int, int> distributeCandy(int N, int M) {
    // Tính tổng số kẹo tối thiểu cần thiết
    long long S = (long long)N * (N + 1) / 2; // Dùng long long để tránh tràn số

    // Kiểm tra nếu không đủ kẹo
    if (M < S) {
        return { -1, -1 };
    }

    // Số kẹo còn lại
    long long R = M - S;

    // Số kẹo ít nhất và nhiều nhất
    int min_candy = 1 + R / N;
    int max_candy = N + R / N + (R % N != 0 ? 1 : 0);

    return { min_candy, max_candy };
}

int main() {
    int N, M;
    cin >> N >> M;
    pair<int, int> result = distributeCandy(N, M);

    if (result.first == -1) {
        cout << -1 << endl;
    }
    else {
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
