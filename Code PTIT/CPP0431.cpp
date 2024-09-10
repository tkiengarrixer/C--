#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        std::vector<long long> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        long long result = 0;
        long long right = 1;
        for (long long left = 0; left < n; ++left) {
            while (right < n && a[right] - a[left] < k) ++right;
            result += (right - left - 1);
        }
        std::cout << result << std::endl;
    }
}