#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::set<int> unique;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            unique.insert(a[i]);
        }
        int min = *std::min_element(a.begin(), a.end());
        int max = *std::max_element(a.begin(), a.end());
        int delta = max - min + 1;
        std::cout << delta - unique.size() << std::endl;
    }
}