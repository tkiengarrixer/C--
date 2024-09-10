#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(3));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) std::cin >> a[i][j];
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int count1 = 0, count0 = 0;
        for (int j = 0; j < 3; ++j) {
            if (a[i][j] == 1)
                ++count1;
            else
                ++count0;
        }
        if (count1 > count0) ++result;
    }
    std::cout << result;
}