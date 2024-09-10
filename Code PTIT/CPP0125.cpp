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
    int a, b;
    std::cin >> a >> b;
    int start = a < b ? a : b;
    int end = a > b ? a : b;
    for (int i = start; i <= end; ++i) {
        if (prime[i]) std::cout << i << " ";
    }
}