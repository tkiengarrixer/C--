#include <algorithm>
#include <iostream>
#include <vector>

std::pair<int, int> countOp(int target) {
    int countDouble = 0;
    int countIncrease = 0;
    while (target > 0) {
        if (target % 2 == 1) {
            target--;
            ++countIncrease;
        } else {
            target /= 2;
            ++countDouble;
        }
    }
    return {countIncrease, countDouble};
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int total = 0;
        int maxDouble = 0;
        for (int i = 0; i < n; ++i) {
            auto pair = countOp(a[i]);
            total += pair.first;
            maxDouble = std::max(maxDouble, pair.second);
        }
        std::cout << total + maxDouble << std::endl;
    }
}