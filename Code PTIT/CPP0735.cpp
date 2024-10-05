#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int findMaxSquare(std::vector<int> &a) {
    int maxSide = 0;
    int m = a.size();

    for (int i = 0; i < m; ++i) {
        int minHeight = a[i];
        for (int j = i; j < m; ++j) {

            // Tìm chiều cao nhỏ nhất từ i đến m
            minHeight = std::min(minHeight, a[j]);
            // Tìm độ dài cạnh nhỏ nhất
            int side = std::min(minHeight, j - i + 1);
            // Tìm độ dài hình vuông lớn nhất
            maxSide = std::max(maxSide, side);
        }
    }
    return maxSide;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        }

        std::vector<std::vector<int>> temp(n, std::vector<int>(m));

        // Tạo histogram
        for (int j = 0; j < m; ++j) temp[0][j] = a[0][j];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j])
                    temp[i][j] = temp[i - 1][j] + 1;
                else
                    temp[i][j] = 0;
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = std::max(result, findMaxSquare(temp[i]));
        }
        std::cout << result << std::endl;
    }
}