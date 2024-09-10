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
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];
        int max = 0;
        for (int i = 0; i < n; ++i) {
            int s1 = 0, s2 = 0;
            for (int j = i; j < n; ++j) {
                s1 += a[j];
                s2 += b[j];
                if (s1 == s2) max = std::max(max, j - i + 1);
            }
        }
        std::cout << max << std::endl;
    }
}