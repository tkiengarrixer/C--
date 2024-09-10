#include <cmath>
#include <iostream>
#include <vector>

int check(long long n) {
    int count = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i % 2 == 0) {
                ++count;
            }
            if (i != n / i && (n / i) % 2 == 0) ++count;
        }
    }
    return count;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        if (n % 2 != 0)
            std::cout << "0";
        else {
            std::cout << check(n);
        }
        std::cout << std::endl;
    }
}
