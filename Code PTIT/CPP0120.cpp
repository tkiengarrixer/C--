#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int m, n, a, b;
        std::cin >> m >> n >> a >> b;
        int count = 0;
        for (int i = m; i <= n; ++i) {
            if (i % a == 0 || i % b == 0) ++count;
        }
        std::cout << count << std::endl;
    }
}