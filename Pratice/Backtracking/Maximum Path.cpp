#include <cmath>
#include <iostream>
#include <vector>

std::vector<std::vector<long long>> a(4, std::vector<long long>(4));
long long result = 0;

void backTrack(int i, int j, long long current) {
    if (i == 3 && j == 3) {
        result = std::max(result, current += a[i][j]);
        return;
    }
    current += a[i][j];
    if (i < 3) backTrack(i + 1, j, current);
    if (j < 3) backTrack(i, j + 1, current);
}

int main() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) std::cin >> a[i][j];
    }
    backTrack(0, 0, 0);
    std::cout << result;
    return 0;
}