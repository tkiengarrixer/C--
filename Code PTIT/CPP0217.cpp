#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        // std::vector<std::vector<int>> a(n, std::vector<int>(n));
        std::vector<int> a(n * n);
        for (int i = 0; i < n * n; ++i) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        std::cout << a[k - 1] << std::endl;
    }
}