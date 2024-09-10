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
        for (int i = 1; i <= n; ++i) {
            if (i == 1)
                std::cout << i << " ";
            else if (i % 2 == 0)
                std::cout << "2" << " ";
            else if (prime[i])
                std::cout << i << " ";
            else {
                for (int j = 2; j <= i; ++j) {
                    if (i % j == 0) {
                        std::cout << j << " ";
                        break;
                    }
                }
            }
        }
        std::cout << std::endl;
    }
}