#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int k, n;
        std::cin >> k >> n;
        int len = k * n;
        std::vector<int> a(len);
        for (int i = 0; i < len; ++i) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        for (int i = 0; i < len; ++i) std::cout << a[i] << " ";
        std::cout << std::endl;
    }
}