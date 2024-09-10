#include <cmath>
#include <iostream>

long long GCD(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long LCM(long long a, long long b) { return a * (b / GCD(a, b)); }

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long x, y, z, n;
        std::cin >> x >> y >> z >> n;
        long long lcm = LCM(LCM(x, y), z);
        long long start = pow(10, n - 1);
        long long end = pow(10, n) - 1;
        long long result = (start + lcm - 1) / lcm * lcm;
        if (result >= start && result <= end) {
            std::cout << result << std::endl;
        } else {
            std::cout << "-1" << std::endl;
        }
    }
}
