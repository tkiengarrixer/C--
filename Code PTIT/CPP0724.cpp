#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

long long kadane(std::vector<long long> &a) {
    long long max_so_far = LLONG_MIN;
    long long max_ending_here = 0;

    for (long long i = 0; i < a.size(); ++i) {
        max_ending_here += a[i];
        max_so_far = std::max(max_so_far, max_ending_here);
        if (max_ending_here < 0) max_ending_here = 0;
    }

    return max_so_far;
}

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n, m;
        long long max = LLONG_MIN;
        std::cin >> n >> m;
        std::vector<std::vector<long long>> a(n, std::vector<long long>(m));

        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < m; ++j) std::cin >> a[i][j];
        }

        for (long long i = 0; i < m; ++i) {
            std::vector<long long> temp(n, 0);
            for (long long j = i; j < m; ++j) {
                for (long long k = 0; k < n; ++k) temp[k] += a[k][j];
                max = std::max(max, kadane(temp));
            }
        }

        std::cout << max << std::endl;
    }
}