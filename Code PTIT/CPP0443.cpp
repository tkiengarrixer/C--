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
        std::set<int> num;
        for (int i = 0; i < n - 1; ++i) {
            int x;
            std::cin >> x;
            num.insert(x);
        }
        int result = 1;
        while (num.find(result) != num.end()) {
            ++result;
        }
        std::cout << result << std::endl;
    }
}