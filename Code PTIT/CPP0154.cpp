#include <iostream>

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        long long sum = 0;
        for (long long i = 1; i <= n; ++i) sum += i % k;
        if (sum == k)
            std::cout << "1";
        else
            std::cout << "0";
        std::cout << std::endl;
    }
}