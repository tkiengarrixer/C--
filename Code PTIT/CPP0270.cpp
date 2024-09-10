#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n, m;
        std::cin >> n >> m;
        std::vector<std::vector<long long>> a(n, std::vector<long long>(m));
        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < m; ++j) std::cin >> a[i][j];
        }
        std::vector<std::vector<long long>> kernel(3,
                                                   std::vector<long long>(3));
        for (long long i = 0; i < 3; ++i) {
            for (long long j = 0; j < 3; ++j) std::cin >> kernel[i][j];
        }
        std::vector<std::vector<long long>> result;
        for (long long i = 0; i < n - 2; ++i) {
            std::vector<long long> temp;
            for (long long j = 0; j < m - 2; ++j) {
                long long sum = 0;
                for (long long u = 0; u < 3; ++u) {
                    for (long long v = 0; v < 3; ++v) {
                        sum += a[i + u][j + v] * kernel[u][v];
                    }
                }
                temp.push_back(sum);
            }
            result.push_back(temp);
        }
        long long total = 0;
        for (long long i = 0; i < result.size(); ++i) {
            for (long long j = 0; j < result[i].size(); ++j) {
                total += result[i][j];
            }
        }
        std::cout << total << std::endl;
    }
}