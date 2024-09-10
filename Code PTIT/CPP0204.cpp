#include <cmath>
#include <iostream>
#include <vector>

std::vector<bool> prime(1000001, true);

void sieve() {
    prime[0] = prime[1] = false;
    for (long long i = 2; i <= 1000; ++i) {
        if (prime[i]) {
            for (long long j = i * i; j < 1000001; j += i) prime[j] = false;
        }
    }
}

int main() {
    sieve();
    int t;
    std::cin >> t;
    while (t--) {
        int l, r;
        std::cin >> l >> r;
        int count = 0;
        for (int i = l; i <= r; ++i)
            if (prime[i]) ++count;
        std::cout << count << std::endl;
    }
}