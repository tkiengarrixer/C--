#include <cmath>
#include <iostream>
#include <vector>

const long long MOD = 1e4 + 7;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b) { return a * b / gcd(a, b); }

int main() {
    long long t;
    std::cin >> t;
    for (long long index = 1; index <= t; ++index) {
        long long n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i];
        long long lim = pow(2, n);
        long long result = 0;
        for (long long i = 1; i < lim; ++i) {
            long long current = 1;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    current = lcm(current, a[j]);
                    if (current >= MOD) current %= MOD;
                }
            }
            result = (result + current) % MOD;
        }
        std::cout << "Case " << index << ": " << result << std::endl;
    }
}