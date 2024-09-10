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
        bool flag = false;
        for (int i = 2; i <= n / 2; ++i) {
            if (prime[i] && prime[n - i]) {
                std::cout << i << " " << n - i;
                flag = true;
                break;
            }
        }
        std::cout << std::endl;
    }
}