#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct để lưu trữ thông tin mỗi cây nấm
struct Mushroom {
    int position;
    int strength;
};

// Hàm chính giải quyết bài toán
long long getMaxStrength(int N, int X, int K, vector<Mushroom>& mushrooms) {
    // Sắp xếp các cây nấm theo tọa độ
    sort(mushrooms.begin(), mushrooms.end(), [](Mushroom a, Mushroom b) {
        return a.position < b.position;
        });

    // Tạo mảng tích lũy cho sức mạnh
    vector<long long> prefixSum(N + 1, 0);

    // Tính mảng tích lũy
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + mushrooms[i].strength;
    }

    // Biến lưu giá trị sức mạnh tối đa
    long long maxStrength = 0;

    // Sử dụng hai con trỏ để tìm đoạn tối ưu
    int left = 0, right = 0;

    // Duyệt từ trái sang phải
    while (right < N) {
        // Nếu khoảng cách nằm trong giới hạn \( K \)
        if (abs(mushrooms[right].position - X) <= K) {
            // Cập nhật sức mạnh tối đa
            maxStrength = max(maxStrength, prefixSum[right + 1] - prefixSum[left]);
            right++;
        }
        else {
            left++;
        }
    }

    return maxStrength;
}

int main() {
    // Đọc dữ liệu từ file
    ifstream inputFile("MARIO.INP");
    ofstream outputFile("MARIO.OUT");

    int N, X, K;
    inputFile >> N >> X >> K;

    vector<Mushroom> mushrooms(N);
    for (int i = 0; i < N; ++i) {
        inputFile >> mushrooms[i].position >> mushrooms[i].strength;
    }

    // Tính kết quả
    long long result = getMaxStrength(N, X, K, mushrooms);

    // Ghi kết quả ra file
    outputFile << result << endl;

    return 0;
}
