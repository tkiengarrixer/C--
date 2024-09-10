#include <cmath>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long x, y, p;
        std::cin >> x >> y >> p;
        long long result = 1;
        x = x % p;
        while (y > 0) {
            if (y % 2 == 1) result = (result * x) % p;
            y = y / 2;
            x = (x * x) % p;
        }
        std::cout << result << std::endl;
    }
}