#include <cmath>
#include <iostream>
#include <vector>

void fact(long long n, long long k) {
    std::vector<long long> a;
    for (long long i = 2; i <= sqrt(n); ++i) {
        long long count = 0;
        while (n % i == 0) {
            a.push_back(i);
            n /= i;
        }
    }
    if (n > 1) a.push_back(n);
    if (k > a.size())
        std::cout << "-1";
    else
        std::cout << a[k - 1];
}

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        fact(n, k);
        std::cout << std::endl;
    }
}