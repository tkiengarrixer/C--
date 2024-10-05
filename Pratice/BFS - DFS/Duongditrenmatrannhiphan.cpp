#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int n, m;
std::vector<std::vector<char>> a;
std::vector<std::vector<bool>> visited;
std::vector<std::vector<int>> distance;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '1' && !visited[i][j];
}
void bfs(int x, int y) {
    distance[x][y] = 0;
    std::queue<std::pair<int, int>> queue;
    queue.push({x, y});
    visited[x][y] = true;

    while (!queue.empty()) {
        std::pair<int, int> current = queue.front();
        queue.pop();
        int currentX = current.first;
        int currentY = current.second;

        for (int i = 0; i < 4; ++i) {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if (isValid(nextX, nextY)) {
                visited[nextX][nextY] = true;
                distance[nextX][nextY] = distance[currentX][currentY] + 1;
                queue.push({nextX, nextY});
            }
        }
    }
}

int main() {
    std::cin >> n >> m;
    a.clear();
    visited.clear();
    distance.clear();
    a.resize(n, std::vector<char>(m));
    visited.resize(n, std::vector<bool>(m, false));
    distance.resize(n, std::vector<int>(m, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) std::cin >> a[i][j];
    }

    bfs(0, 0);

    std::cout << distance[n - 1][m - 1];

}
