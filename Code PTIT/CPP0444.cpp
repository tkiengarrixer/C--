#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int index = -2;
        for (int i = 0; i < n; ++i) {
            if (a[i] == x) {
                index = i;
                break;
            }
        }
        std::cout << index + 1 << std::endl;
    }
}