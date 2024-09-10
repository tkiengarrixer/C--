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

bool isSphenic(int n) {
    int count = 0;
    for (int i = 2; i < 1000001; ++i) {
        if (prime[i] && n % i == 0) {
            ++count;
            n /= i;
            if (n % i == 0) return false;
        }
        if (count == 3) break;
    }
    return count == 3 && n == 1;
}

int main() {
    sieve();
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (isSphenic(n))
            std::cout << "1";
        else
            std::cout << "0";
        std::cout << std::endl;
    }
}