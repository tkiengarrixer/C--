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
        long long l, r;
        std::cin >> l >> r;
        int count = 0;
        for (int i = ceil(sqrt(l)); i <= floor(sqrt(r)); ++i) {
            if (prime[i]) ++count;
        }
        std::cout << count << std::endl;
    }
}