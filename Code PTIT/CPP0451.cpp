#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k, x;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::cin >> k >> x;
        std::sort(a.begin(), a.end());
        int index = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == x) {
                index = i;
                break;
            }
        }
        for (int i = index - (k / 2); i < index; ++i) std::cout << a[i] << " ";
        for (int i = index + 1; i <= index + (k / 2); ++i)
            std::cout << a[i] << " ";
        std::cout << std::endl;
    }
}