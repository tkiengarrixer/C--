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
        if (n < 2) {
            std::cout << "-1";
        } else {
            int min = a[0];
            int diff = -1e9;
            for (int i = 1; i < n; ++i) {
                diff = std::max(diff, a[i] - min);
                min = std::min(min, a[i]);
            }
            if (diff > 0)
                std::cout << diff;
            else
                std::cout << "-1";
        }
        std::cout << std::endl;
    }
}