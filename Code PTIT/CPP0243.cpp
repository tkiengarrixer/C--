#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> a(n);
        std::vector<int> b(m);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < m; ++i) std::cin >> b[i];
        std::vector<int> result(n);
        std::map<int, int> map;
        for (int i = 0; i < n; ++i) {
            ++map[a[i]];
        }
        std::sort(a.begin(), a.end());
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= map[b[i]]; ++j) result[count++] = b[i];
            map[b[i]] = 0;
        }
        for (int i = 0; i < n; ++i) {
            if (map[a[i]]) result[count++] = a[i];
        }
        for (int i = 0; i < n; ++i) std::cout << result[i] << " ";
        std::cout << std::endl;
    }
}