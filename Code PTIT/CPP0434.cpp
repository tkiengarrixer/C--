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
        std::vector<long long> temp = a;
        a[0] = a[0] * a[1];
        a[n - 1] = a[n - 1] * a[n - 2];
        for (long long i = 1; i < n - 1; ++i) {
            a[i] = temp[i - 1] * temp[i + 1];
        }
        for (long long i = 0; i < n; ++i) std::cout << a[i] << " ";
        std::cout << std::endl;
    }
}