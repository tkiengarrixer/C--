#include <cmath>
#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        long long sum = a[0];
        for (int i = 1; i < n; ++i) {
            sum = (sum * x + a[i]) % MOD;
        }
        std::cout << sum << std::endl;
    }
}