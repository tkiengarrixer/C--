#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        long long include = a[0];
        long long exclude = 0;
        long long excludeNew;

        for (long long i = 1; i < n; ++i) {
            excludeNew = std::max(include, exclude);
            include = exclude + a[i];
            exclude = excludeNew;
        }

        std::cout << std::max(include, exclude) << std::endl;
    }
}