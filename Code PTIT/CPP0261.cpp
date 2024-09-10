#include <iostream>
#include <vector>

int main() {
    long long n;
    std::cin >> n;
    std::vector<std::vector<long long>> a(n, std::vector<long long>(n));
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) std::cin >> a[i][j];
    }
    long long m;
    std::cin >> m;
    std::vector<std::vector<long long>> b(m, std::vector<long long>(m));
    for (long long i = 0; i < m; ++i) {
        for (long long j = 0; j < m; ++j) std::cin >> b[i][j];
    }
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            for (long long u = 0; u < m; ++u) {
                for (long long v = 0; v < m; ++v) {
                    if (i % m == 0 && j % m == 0) {
                        a[i + u][j + v] = a[i + u][j + v] * b[u][v];
                    }
                }
            }
        }
    }
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }
}