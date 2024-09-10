#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

int find(std::vector<long long> &a) {
    std::unordered_set<long long> us;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > 0) us.insert(a[i]);
    }
    int smallest = 1;
    while (us.find(smallest) != us.end()) ++smallest;
    return smallest;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::cout << find(a) << std::endl;
    }
}