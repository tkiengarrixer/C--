#include <algorithm>
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

long long GCD(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    sieve();
    int t;
    std::cin >> t;
    while (t--) {
        int x;
        std::cin >> x;
        int count = 0;
        for (int i = 1; i < x; ++i) {
            if (GCD(i, x) == 1) ++count;
        }
        if (prime[count])
            std::cout << "1";
        else
            std::cout << "0";
        std::cout << std::endl;
    }
}