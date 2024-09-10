#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> a(n, std::vector<int>(n));
        std::vector<int> rowSum(n);
        std::vector<int> colSum(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> a[i][j];
                rowSum[i] += a[i][j];
                colSum[j] += a[i][j];
            }
        }
        int maxSum = 0;
        for (int i = 0; i < n; ++i) maxSum = std::max(maxSum, rowSum[i]);
        for (int i = 0; i < n; ++i) maxSum = std::max(maxSum, colSum[i]);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += (maxSum - rowSum[i]);
            result += (maxSum - colSum[i]);
        }
        std::cout << result / 2 << std::endl;
    }
}