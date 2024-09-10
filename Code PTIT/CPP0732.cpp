#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i];
        std::vector<long long> dp = a;
        for (long long i = 1; i < n; ++i) {
            for (long long j = 0; j < i; ++j) {
                if (a[j] < a[i]) dp[i] = std::max(dp[i], dp[j] + a[i]);
            }
        }
        std::cout << *std::max_element(dp.begin(), dp.end()) << std::endl;
    }
}