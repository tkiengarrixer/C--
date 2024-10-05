#include <cmath>
#include <iostream>
#include <vector>

const double EPSILON = 1e-9;

// Dùng phương pháp khử Gauss
void gaussElimination(std::vector<std::vector<double>> &a, int n, int m) {
    int row = 0;
    for (int col = 0; col < m && row < n; ++col) {
        // Tìm hàng giá trị lớn nhất trong cột hiện tại (pivot)
        int pivotRow = row;
        for (int i = row; i < n; ++i) {
            if (fabs(a[i][col]) > fabs(a[pivotRow][col])) pivotRow = i;
        }

        // Nếu giá trị tại pivot = 0 thì bỏ qua cột này
        if (fabs(a[pivotRow][col]) < EPSILON) continue;

        // Đảo chỗ 2 hàng
        std::swap(a[pivotRow], a[row]);

        // Chia hàng pivot cho giá trị tại pivot để đưa về 1
        for (int j = m - 1; j >= col; --j) a[row][j] /= a[row][col];

        // Loại bỏ các hàng khác trong cột hiện tại
        for (int i = 0; i < n; ++i) {
            if (i != row && fabs(a[i][col]) > EPSILON) {
                double ratio = a[i][col];
                for (int j = col; j < m; ++j) a[i][j] -= ratio * a[row][j];
            }
        }
        ++row;
    }
}

int matrix(std::vector<std::vector<double>> &a, int n, int m) {
    int rank = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = 0; j < m; ++j) {
            if (fabs(a[i][j]) > EPSILON) {
                flag = true;
                break;
            }
        }
        if (flag) ++rank;
    }
    return rank;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<double>> a(n, std::vector<double>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        }
        gaussElimination(a, n, m);
        std::cout << matrix(a, n, m) << std::endl;
    }
}