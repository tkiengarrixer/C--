#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::vector<long long> result(n, -1);
        for (int i = 0; i < n; ++i) {
            if (a[i] >= 0 && a[i] < n) result[a[i]] = a[i];
        }
        for (int i = 0; i < n; ++i) std::cout << result[i] << " ";
        std::cout << std::endl;
    }
}