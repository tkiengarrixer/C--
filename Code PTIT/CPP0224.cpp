#include <cmath>
#include <iostream>
#include <vector>

int n, m;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }

void dfs(int i, int j, std::vector<std::vector<int>> &a) {
    a[i][j] = 0;
    for (int k = 0; k < 8; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (isValid(x, y) && a[x][y] == 1) dfs(x, y, a);
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j]) {
                    ++count;
                    dfs(i, j, a);
                }
            }
        }
        std::cout << count << std::endl;
    }
}