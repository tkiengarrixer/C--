#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        if (n % 2 != 0) {
            for (int i = 0; i < n / 2; ++i)
                std::cout << a[n - i - 1] << " " << a[i] << " ";
            std::cout << a[n / 2];
        } else {
            for (int i = 0; i <= (n - 1) / 2; ++i)
                std::cout << a[n - i - 1] << " " << a[i] << " ";
        }
        std::cout << std::endl;
    }
}