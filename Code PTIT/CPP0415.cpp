#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n, m;
        std::cin >> n >> m;
        long long min = 1e9;
        long long max = -1e9;
        for (long long i = 0; i < n; ++i) {
            long long a;
            std::cin >> a;
            max = std::max(max, a);
        }
        for (long long i = 0; i < m; ++i) {
            long long b;
            std::cin >> b;
            min = std::min(min, b);
        }
        std::cout << max * min << std::endl;
    }
}