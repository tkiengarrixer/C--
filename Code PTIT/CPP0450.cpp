#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::unordered_set<int> seen;
        int first = -1;
        for (int i = 0; i < n; ++i) {
            if (seen.find(a[i]) != seen.end()) {
                first = a[i];
                break;
            }
            seen.insert(a[i]);
        }

        std::cout << first << std::endl;
    }
    return 0;
}
