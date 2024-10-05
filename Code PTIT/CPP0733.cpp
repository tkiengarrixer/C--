#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, x, y, z, t;
std::vector<std::vector<bool>> visited;
std::vector<std::vector<int>> a;

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && a[i][j] == 1 && !visited[i][j];
}

int bfs() {
    std::queue<std::tuple<int, int, int>> q;

    // Đẩy ô đầu tiên vào hàng đợi
    q.push(std::make_tuple(x, y, 0));

    while (!q.empty()) {
        // Lấy hàng đợi
        auto [currentX, currentY, distance] = q.front();
        q.pop();

        if (currentX == z && currentY == t) return distance;

        // Duyệt qua các ô lân cận và đẩy vào hàng đợi nếu chưa được thăm
        for (int i = 0; i < 4; ++i) {
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];

            if (isValid(newX, newY)) {
                visited[newX][newY] = true;
                q.push(std::make_tuple(newX, newY, distance + 1));
            }
        }
    }

    return -1;
}

int main() {
    int test;
    std::cin >> test;
    while (test--) {
        std::cin >> n >> m >> x >> y >> z >> t;

        a.clear();
        visited.clear();
        a.resize(n, std::vector<int>(m));
        visited.assign(n, std::vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        }

        if (a[x][y] == 0 || a[z][t] == 0) {
            std::cout << "-1" << std::endl;
            continue;
        }

        std::cout << bfs() << std::endl;
    }
}