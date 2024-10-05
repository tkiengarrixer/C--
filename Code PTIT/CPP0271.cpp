#include <cmath>
#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n, m, l;
        std::cin >> n >> m >> l;
        std::vector<std::vector<long long>> a(n, std::vector<long long>(m));
        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < m; ++j) std::cin >> a[i][j];
        }
        std::vector<std::vector<long long>> result;
        for (long long i = 0; i < n - l + 1; ++i) {
            std::vector<long long> temp;
            for (long long j = 0; j < m - l + 1; ++j) {
                long long sum = 0;
                for (long long u = 0; u < l; ++u) {
                    for (long long v = 0; v < l; ++v) {
                        sum += a[i + u][j + v];
                    }
                }
                long long value = floor(sum / (l * l));
                temp.push_back(value);
            }
            result.push_back(temp);
        }
        for (long long i = 0; i < result.size(); ++i) {
            for (long long j = 0; j < result[i].size(); ++j) {
                std::cout << result[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}