#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        long long result = 1e9;
        for (int i = 0; i < n - 1; ++i) {
            long long delta = abs(a[i] - a[i + 1]);
            result = std::min(result, delta);
        }
        std::cout << result << std::endl;
    }
}