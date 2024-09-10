#include <cmath>
#include <iostream>

void fact(long long n) {
    for (long long i = 2; i <= sqrt(n); ++i) {
        long long count = 0;
        while (n % i == 0) {
            std::cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) std::cout << n;
}

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        fact(n);
        std::cout << std::endl;
    }
}