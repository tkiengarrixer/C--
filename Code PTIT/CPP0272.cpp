#include <cmath>
#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long pow(long long x, long long y, long long mod) {
    long long result = 1;
    x = x % mod;
    while (y > 0) {  // den khi mu bang 0
        if (y % 2 == 1)
            result =
                (result * x) % mod;  // neu mu le, nhan them co so vao ket qua
        y /= 2;                      // chia so mu cho 2
        x = (x * x) % mod;           // binh phuong co so
    }
    return result;
}

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i];
        long long h = 1;
        long long g = 0;
        for (long long i = 0; i < n; ++i) {
            g = gcd(g, a[i]);
            h = ((h % MOD) * (a[i] % MOD)) % MOD;
        }
        long long result = pow(h, g, MOD) % MOD;
        std::cout << result << std::endl;
    }
}