#include <iostream>

long long GCD(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long LCM(long long a, long long b) { return a * b / GCD(a, b); }

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b;
        std::cin >> a >> b;
        std::cout << LCM(a, b) << " " << GCD(a, b) << std::endl;
    }
}