#include <iostream>
#include <vector>

int main() {
    int n, m, p;
    std::cin >> n >> m >> p;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    std::vector<std::vector<int>> b(m, std::vector<int>(p));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) std::cin >> a[i][j];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) std::cin >> b[i][j];
    }
    std::vector<std::vector<int>> c(n, std::vector<int>(p, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) c[i][j] += a[i][k] * b[k][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) std::cout << c[i][j] << " ";
        std::cout << std::endl;
    }
}