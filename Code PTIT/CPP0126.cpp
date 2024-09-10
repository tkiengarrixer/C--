#include <cmath>
#include <iostream>
#include <vector>

std::vector<bool> prime(1000001, true);

void sieve() {
    prime[0] = prime[1] = false;
    for (int i = 2; i <= 1000; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < 1000001; j += i) prime[j] = false;
        }
    }
}

int main() {
    sieve();
    int t;
    std::cin >> t;
    while (t--) {
        int m, n;
        std::cin >> m >> n;
        for (int i = m; i <= n; ++i) {
            if (prime[i]) std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}