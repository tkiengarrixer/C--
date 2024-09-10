#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::vector<int> temp = a;
        std::sort(temp.begin(), temp.end());
        std::vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (a[i] != temp[i]) result.push_back(i + 1);
        }
        std::cout << result[0] << " " << result[result.size() - 1] << std::endl;
    }
}