#include <cmath>
#include <iostream>
#include <string>

long long GCD(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long a, x, y;
        std::cin >> a >> x >> y;
        long long times = GCD(x, y);
        std::string result = std::to_string(a);
        for (int i = 1; i < times; ++i) result += std::to_string(a);
        std::cout << result << std::endl;
    }
}