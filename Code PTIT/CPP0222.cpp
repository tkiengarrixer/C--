#include <iostream>
#include <map>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> a(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) std::cin >> a[i][j];
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int k = 1; k < n; ++k) {
                for (int l = 0; l < n; ++l) {
                    if (a[0][i] == a[k][l]) {
                        ++count;
                        break;
                    }
                }
            }
            int flag = 1;
            for (int j = 0; j < i; ++j) {
                if (a[0][i] == a[0][j]) flag = 0;
            }
            if (flag && count == n - 1) {
                ++result;
                flag = 1;
            }
        }
        std::cout << result << std::endl;
    }
}