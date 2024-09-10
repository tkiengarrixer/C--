#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        bool found = std::binary_search(a.begin(), a.end(), x);
        if (found)
            std::cout << "1";
        else
            std::cout << "-1";
        std::cout << std::endl;
    }
}