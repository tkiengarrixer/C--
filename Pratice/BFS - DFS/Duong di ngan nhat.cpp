#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int n, m;
std::vector<std::vector<int>> a;
std::vector<bool> visited;
std::vector<int> distance;

void bfs(int x) {
    std::queue<int> queue;
    queue.push(x);
    distance[x] = 0;

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        for (int v = 0; v < a[u].size(); ++v) {
            if (!visited[a[u][v]]) {
                visited[a[u][v]] = true;
                distance[a[u][v]] = distance[u] + 1;
                queue.push(a[u][v]);
            }
        }
    }
}

int main() {
    std::cin >> n >> m;
    a.clear();
    visited.clear();
    a.resize(n + 1);
    distance.clear();
    visited.resize(n + 1, false);
    distance.resize(n + 1, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    bfs(1);
    for (int i = 2; i <= n; ++i) std::cout << distance[i] << " ";
    return 0;
}