#include <iostream>
#include <vector>

int dx[] = {1, 0};
int dy[] = {0, 1};
int n, k, count = 0;
std::vector<std::vector<int>> a;

bool isValid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < n; }

void backTrack(int i, int j, int sum) {
    if (sum == k && i == n - 1 && j == n - 1) {
        ++count;
        return;
    }
    for (int t = 0; t < 2; ++t) {
        int x = i + dx[t];
        int y = j + dy[t];
        if (isValid(x, y)) {
            backTrack(x, y, sum + a[x][y]);
        }
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> k;
        count = 0;
        a.resize(n, std::vector<int>(n));
        bool visited = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) std::cin >> a[i][j];
        }
        backTrack(0, 0, a[0][0]);
        std::cout << count << std::endl;
    }
}