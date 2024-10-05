#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int n;
std::vector<int> a;

int bfs() {
    if (n == 1) return 0;
    std::vector<int> step(n, 1e9);
    std::queue<int> queue;

    queue.push(0);
    step[0] = 0;

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();
        int jump = a[current];

        for (int i = 1; i <= jump; ++i) {
            int next = current + i;
            if (next > n) break;
            if (step[next] > step[current] + 1) {
                step[next] = step[current] + 1;
                queue.push(next);
            }
        }
    }

    return step[n - 1] == 1e9 ? -1 : step[n - 1];
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        a.clear();
        a.resize(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::cout << bfs() << std::endl;
    }
}