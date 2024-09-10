#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        long long sum = 0;
        sum = (1 + n) * (long long)n / 2;
        std::cout << sum << "\n";
    }
    return 0;
}