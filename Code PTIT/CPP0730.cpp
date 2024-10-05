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

/*
Hoặc dùng prefix sum:

#include <climits>
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

        std::vector<long long> prefix(n);
        prefix[0] = a[0];
        for (long long i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + a[i];
        }

        long long max = LLONG_MIN;
        long long min = 0;

        for (long long i = 0; i < n; ++i) {
            max = std::max(max, prefix[i] - min);
            min = std::min(min, prefix[i]);
        }

        std::cout << max << std::endl;
    }

    return 0;
}

*/