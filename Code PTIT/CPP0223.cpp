#include <iostream>
#include <vector>

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
        int r1 = 0, c1 = 0, r2 = n - 1, c2 = m - 1;
        while (r1 <= r2 && c1 <= c2) {
            for (int i = c1; i <= c2; ++i) std::cout << a[r1][i] << " ";
            ++r1;
            for (int i = r1; i <= r2; ++i) std::cout << a[i][c2] << " ";
            --c2;
            if (r1 <= r2) {
                for (int i = c2; i >= c1; --i) std::cout << a[r2][i] << " ";
                --r2;
            }
            if (c1 <= c2) {
                for (int i = r2; i >= r1; --i) std::cout << a[i][c1] << " ";
                ++c1;
            }
        }
        std::cout << std::endl;
    }
}