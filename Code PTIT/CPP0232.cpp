#include <algorithm>
#include <iostream>
#include <vector>

int findMaxArea(std::vector<std::vector<int>> &a, int n, int m) {
    int max = 0;
    for (int i = 0; i < n; ++i) {
        std::vector<int> sort = a[i];
        std::sort(sort.rbegin(), sort.rend());

        for (int j = 0; j < m; ++j) {
            int width = j + 1;
            int area = sort[j] * width;
            max = std::max(max, area);
        }
    }

    return max;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        }

        std::vector<std::vector<int>> temp(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0)
                    temp[i][j] = a[i][j];
                else if (a[i][j])
                    temp[i][j] = temp[i - 1][j] + 1;
                else
                    temp[i][j] = 0;
            }
        }

        std::cout << findMaxArea(temp, n, m) << std::endl;
    }
}