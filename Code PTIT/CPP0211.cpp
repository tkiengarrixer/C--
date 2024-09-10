#include <cmath>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int max = -1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= i; --j) {
                if (j - i < max) break;
                if (a[i] < a[j]) {
                    max = std::max(max, j - i);
                }
            }
        }
        std::cout << max << std::endl;
    }
}