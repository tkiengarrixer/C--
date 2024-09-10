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
    long long t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        long long result = 1;
        for (long long i = 1; i <= n; ++i) {
            result = LCM(result, i);
        }
        std::cout << result << std::endl;
    }
}