#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] <= k) ++count;
        }
        int greater = 0;
        for (int i = 0; i < count; ++i) {
            if (a[i] > k) ++greater;
        }
        int result = greater;
        int left = 0, right = count;
        while (right < n) {
            if (a[left] > k) --greater;
            if (a[right] > k) ++greater;
            result = std::min(result, greater);
            ++right;
            ++left;
        }
        std::cout << result << std::endl;
    }
}