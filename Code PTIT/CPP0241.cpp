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
        int left = 0, right = n - 1;
        int count = 0;
        while (left < right) {
            if (a[left] == a[right]) {
                ++left;
                --right;
            } else if (a[left] < a[right]) {
                a[left + 1] = a[left] + a[left + 1];
                ++count;
                ++left;
            } else {
                a[right - 1] = a[right] + a[right - 1];
                ++count;
                --right;
            }
        }
        std::cout << count << std::endl;
    }
}