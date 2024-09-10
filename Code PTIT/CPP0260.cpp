#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> result(n, std::vector<int>(n));
    std::vector<int> a(n * n);
    for (int i = 0; i < n * n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int count = 0;
    int r1 = 0, c1 = 0, r2 = n - 1, c2 = n - 1;

    while (r1 <= r2 && c1 <= c2) {
        for (int i = c1; i <= c2; ++i) result[r1][i] = a[count++];
        ++r1;
        for (int i = r1; i <= r2; ++i) result[i][c2] = a[count++];
        --c2;
        if (r1 <= r2) {
            for (int i = c2; i >= c1; --i) result[r2][i] = a[count++];
            --r2;
        }
        if (c1 <= c2) {
            for (int i = r2; i >= r1; --i) result[i][c1] = a[count++];
            ++c1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) std::cout << result[i][j] << " ";
        std::cout << std::endl;
    }
}