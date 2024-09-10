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
        long long result = -1e9;
        for (int i = 0; i < n; ++i) result = std::max(result, a[i]);
        std::cout << result << std::endl;
    }
}