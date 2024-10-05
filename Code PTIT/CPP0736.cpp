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

        std::vector<int> prefix(n);
        prefix[0] = a[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + a[i];
        }

        int result = 1e9;
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int currentSum;

                if (i > 0)
                    currentSum = prefix[mid] - prefix[i - 1];
                else
                    currentSum = prefix[mid];

                if (currentSum > x) {
                    result = std::min(result, mid - i + 1);
                    right = mid - 1;
                } else
                    left = mid + 1;
            }
        }

        if (result == 1e9) result = -1;
        std::cout << result << std::endl;
    }
    return 0;
}
