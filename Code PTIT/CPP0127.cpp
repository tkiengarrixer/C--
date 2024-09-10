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
        int n;
        std::cin >> n;
        bool found = false;
        for (int i = 2; i <= n / 2; ++i) {
            if (prime[i] && prime[n - i]) {
                std::cout << i << " " << n - i << std::endl;
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "-1" << std::endl;
        }
    }
    return 0;
}
