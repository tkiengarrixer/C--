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
        long long maxEnd = a[0];
        long long maxSoFar = a[0];
        for (long long i = 1; i < n; ++i) {
            maxEnd = std::max(maxEnd + a[i], a[i]);
            maxSoFar = std::max(maxSoFar, maxEnd);
        }
        std::cout << maxSoFar << std::endl;
    }
}