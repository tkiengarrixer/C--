#include <algorithm>
#include <iostream>
#include <vector>

// Tạo mảng tổng tiền tố cho các đường chéo chính
std::vector<std::vector<int>> mainPrefix(std::vector<std::vector<int>> &a,
                                         int n) {
    std::vector<std::vector<int>> mainDiag(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mainDiag[i][j] = a[i][j];
            if (i > 0 && j > 0) mainDiag[i][j] += mainDiag[i - 1][j - 1];
        }
    }

    return mainDiag;
}

// Tạo mảng tổng tiền tố cho các đường chéo phụ
std::vector<std::vector<int>> secondPrefix(std::vector<std::vector<int>> &a,
                                           int n) {
    std::vector<std::vector<int>> secondDiag(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            secondDiag[i][j] = a[i][j];
            if (i > 0 && j < n - 1)
                secondDiag[i][j] += secondDiag[i - 1][j + 1];
        }
    }

    return secondDiag;
}

int maxValue(std::vector<std::vector<int>> &a, int n) {
    int max = -1e9;
    std::vector<std::vector<int>> mainDiag = mainPrefix(a, n);
    std::vector<std::vector<int>> secondDiag = secondPrefix(a, n);

    for (int size = 1; size <= n; ++size) {
        for (int i = 0; i <= n - size; ++i) {
            for (int j = 0; j <= n - size; ++j) {
                // Tổng đường chéo chính của ma trận con
                int main = mainDiag[i + size - 1][j + size - 1];
                if (i > 0 && j > 0) main -= mainDiag[i - 1][j - 1];

                // Tổng đường chéo phụ của ma trận con
                int second = secondDiag[i + size - 1][j];
                if (i > 0 && j + size < n)
                    second -= secondDiag[i - 1][j + size];

                max = std::max(max, main - second);
            }
        }
    }

    return max;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) std::cin >> a[i][j];

    std::cout << maxValue(a, n) << std::endl;

    return 0;
}
