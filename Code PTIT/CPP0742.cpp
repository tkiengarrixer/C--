#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

int min(std::vector<int> &a, int n) {
    std::vector<std::pair<int, int>> sorted(n);
    for (int i = 0; i < n; ++i) {
        sorted[i].first = a[i];
        sorted[i].second = i;
    }

    std::sort(sorted.begin(), sorted.end());
    std::vector<bool> visited(n, false);
    
    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i] || sorted[i].second == i) continue;
        int count = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = sorted[j].second;
            ++count;
        }

        if (count > 1)
        result += (count - 1);
    }

    return result;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::cout << min(a, n) << std::endl;
    }
}