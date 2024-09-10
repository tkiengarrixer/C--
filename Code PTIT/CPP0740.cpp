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
        long long result = -1e18;
        for (long long i = 0; i < n; ++i) {
            long long temp = 1;
            for (long long j = i; j < n; ++j) {
                temp *= a[j];
                result = std::max(result, temp);
            }
        }
        std::cout << result << std::endl;
    }
    return 0;
}