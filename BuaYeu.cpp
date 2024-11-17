#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Hàm tính hiệu quả của bùa
int calculateEffectiveness(int a, int b) {
    return a * a - b * b;
}

// Hàm tối ưu hóa để chuyển các cặp chưa phải "OK" thành "OK"
void optimizeCharm(string& charm, int& a, int& b, int k) {
    int n = charm.size();
    int swaps = 0;

    // Duyệt qua chuỗi để tìm các cặp "KO" và chuyển thành "OK"
    for (int i = 0; i < n - 1 && swaps < k; ++i) {
        if (charm[i] == 'K' && charm[i + 1] == 'O') {
            // Chuyển "KO" thành "OK"
            charm[i] = 'O';
            charm[i + 1] = 'K';
            ++a;
            --b;
            ++swaps;
        }
    }

    // Nếu vẫn còn swaps, tìm các vị trí "O" và "K" rời rạc để tạo thêm "OK"
    for (int i = 0; i < n - 1 && swaps < k; ++i) {
        if (charm[i] == 'K' && charm[i + 1] != 'O') {
            // Tìm vị trí "O" tiếp theo để hoán đổi
            for (int j = i + 1; j < n; ++j) {
                if (charm[j] == 'O') {
                    swap(charm[i + 1], charm[j]);
                    ++a;
                    ++swaps;
                    break;
                }
            }
        }
    }
}

// Hàm tối ưu hóa hiệu quả
int maximizeEffectiveness(string& charm, int n, int k) {
    int a = 0, b = 0; // Đếm số cặp "OK" và "KO"

    // Đếm các cặp "OK" và "KO" ban đầu
    for (int i = 0; i < n - 1; ++i) {
        if (charm[i] == 'O' && charm[i + 1] == 'K') {
            ++a;
        }
        else if (charm[i] == 'K' && charm[i + 1] == 'O') {
            ++b;
        }
    }

  

    // Gọi hàm tối ưu hóa để chuyển đổi các cặp thành "OK" nhiều nhất có thể
    optimizeCharm(charm, a, b, k);

    // Cập nhật lại hiệu quả tối đa sau khi xếp bùa
   int maxEffectiveness = calculateEffectiveness(a, b);

    return maxEffectiveness;
}

int main() {
    int t; // Số lượng test cases
    cout << "Nhập số lượng test cases: ";
    cin >> t;

    vector<int> results; // Danh sách lưu trữ kết quả

    for (int i = 0; i < t; ++i) {
        int n, k;
        string charm;

        cout << "Nhập n và k cho test case " << i + 1 << ": ";
        cin >> n >> k;
        cout << "Nhập chuỗi charm: ";
        cin >> charm;

        // Tính toán hiệu quả cho từng bùa
        int effectiveness = maximizeEffectiveness(charm, n, k);
        results.push_back(effectiveness); // Lưu kết quả vào danh sách
    }

    // In ra tất cả các kết quả
    cout << "Các kết quả hiệu quả của từng lá bùa: " << endl;
    for (int i = 0; i < results.size(); ++i) {
        cout << "Test case " << i + 1 << ": " << results[i] << endl;
    }

    return 0;
}
