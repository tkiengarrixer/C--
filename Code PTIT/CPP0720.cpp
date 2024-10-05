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
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        std::vector<int> up(n, 1);
        std::vector<int> down(n, 1);

        // Tìm độ dài các dãy con tăng dần
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i] > a[j]) up[i] = std::max(up[i], up[j] + 1);
            }
        }

        // Tìm độ dài các dãy con giảm dần
        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (a[i] > a[j]) down[i] = std::max(down[i], down[j] + 1);
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i)
            result = std::max(result, up[i] + down[i] - 1);

        std::cout << result << std::endl;
    }
}