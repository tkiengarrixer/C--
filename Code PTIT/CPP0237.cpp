#include <iostream>
#include <vector>

bool isValid(std::vector<std::vector<char>> &a, int row, int col, int size) {
    // Kiểm tra viền trái
    for (int i = row; i <= row + size - 1; ++i)
        if (a[i][col] != 'X') return false;

    // Kiểm tra viền phải
    for (int i = row; i <= row + size - 1; ++i)
        if (a[i][col + size - 1] != 'X') return false;

    // Kiểm tra viền trên
    for (int i = col; i <= col + size - 1; ++i)
        if (a[row][i] != 'X') return false;

    // Kiểm tra viền dưới
    for (int i = col; i <= col + size - 1; ++i)
        if (a[row + size - 1][i] != 'X') return false;
    return true;
}

int maxSize(std::vector<std::vector<char>> &a, int n) {
    // Thu nhỏ dần dần cấp ma trận và kiểm tra các ma trận con
    for (int size = n; size >= 1; --size) {
        for (int i = 0; i <= n - size; ++i) {
            for (int j = 0; j <= n - size; ++j) {
                if (isValid(a, i, j, size)) return size;
            }
        }
    }
    return 0;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<char>> a(n, std::vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) std::cin >> a[i][j];
        }
        std::cout << maxSize(a, n) << std::endl;
    }
}
