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
        int totalSum = 0;
        for (int i = 0; i < n; ++i) {
            totalSum += a[i];
        }

        int sumLeft = 0;
        int index = -2;
        for (int i = 0; i < n; ++i) {
            int sumRight = totalSum - sumLeft - a[i];
            if (sumLeft == sumRight) {
                index = i;
                break;
            }
            sumLeft += a[i];
        }

        std::cout << index + 1 << std::endl;
    }
}
