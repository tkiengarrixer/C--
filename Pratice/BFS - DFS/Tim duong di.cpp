#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int n, m;
std::vector<std::vector<int>> a;
std::vector<bool> visited;
std::vector<int> distance;
std::vector<int> vertex;
std::vector<int> path;

void bfs(int x) {
    std::queue<int> queue;
    queue.push(x);
    visited[x] = true; 
    distance[x] = 0;

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        for (int i = 0; i < a[u].size(); ++i) {
            int v = a[u][i];
            if (!visited[v]) {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                path[v] = u; 
                queue.push(v);
            }
        }
    }
}

int main() {
    std::cin >> n >> m;
    a.clear();
    a.resize(n + 1);
    visited.clear();
    visited.resize(n + 1, false);
    distance.clear();
    distance.resize(n + 1, -1);
    path.clear();
    path.resize(n + 1, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    bfs(1);


    std::cout << distance[n] << std::endl;

    for (int i = n; i != -1; i = path[i]) {
        vertex.push_back(i);
    }

    std::reverse(vertex.begin(), vertex.end());

    for (int i = 0; i < vertex.size(); ++i) {
        std::cout << vertex[i] << " ";
    }

    return 0;
}
