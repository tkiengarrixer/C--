#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> result;
        for (int i = 0; i < n + m; ++i) {
            int num;
            std::cin >> num;
            result.push_back(num);
        }
        std::sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i) std::cout << result[i] << " ";
        std::cout << std::endl;
    }
}