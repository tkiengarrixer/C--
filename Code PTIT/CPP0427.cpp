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
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == a[i + 1]) {
                a[i] = a[i + 1] * 2;
                a[i + 1] = 0;
            }
        }
        std::vector<int> result(n, 0);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != 0) result[count++] = a[i];
        }
        for (int i = 0; i < n; ++i) std::cout << result[i] << " ";
        std::cout << std::endl;
    }
}