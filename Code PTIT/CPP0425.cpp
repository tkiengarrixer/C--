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
        std::vector<int> result(n);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) result[i] = a[count++];
        }
        for (int i = 0; i < n; ++i) {
            if (i % 2 != 0) result[i] = a[count++];
        }
        for (int i = 0; i < n; ++i) std::cout << result[i] << " ";
        std::cout << std::endl;
    }
}