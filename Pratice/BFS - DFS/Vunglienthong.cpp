#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int n, m;
std::vector<bool> visited;
std::vector<std::vector<int>> a;

void dfs(int i) {
    visited[i] = true;
    for (int j = 0; j < a[i].size(); ++j) {
        if (!visited[a[i][j]]) dfs(a[i][j]);
    }
}

int main() {
    std::cin >> n >> m;
    a.clear();
    visited.clear();
    a.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
            ++count;
        }
    }

    std::cout << count;
    return 0;
}