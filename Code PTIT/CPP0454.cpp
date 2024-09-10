#include <algorithm>
#include <cmath>
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
        std::sort(a.begin(), a.end());
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            int left = 0, right = n - 1;
            while (left < right) {
                if (a[left] * a[left] + a[right] * a[right] == a[i] * a[i]) {
                    flag = true;
                    break;
                } else if (a[left] * a[left] + a[right] * a[right] <
                           a[i] * a[i]) {
                    ++left;
                } else
                    --right;
            }
            if (flag) break;
        }
        if (flag)
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << std::endl;
    }
}