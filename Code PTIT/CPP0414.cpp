#include <iostream>
#include <set>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i];
        std::vector<int> container;
        for (long long i = 0; i < n; ++i) {
            while (a[i] != 0) {
                container.push_back(a[i] % 10);
                a[i] /= 10;
            }
        }
        std::set<int> result;
        for (int i = 0; i < container.size(); ++i) result.insert(container[i]);
        for (int num : result) std::cout << num << " ";
        std::cout << std::endl;
    }
}