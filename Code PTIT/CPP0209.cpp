#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, q;
        std::cin >> n >> q;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        while (q--) {
            int l, r;
            std::cin >> l >> r;
            --l, --r;
            int sum = 0;
            for (int i = l; i <= r; ++i) sum += a[i];
            std::cout << sum << std::endl;
        }
    }
}