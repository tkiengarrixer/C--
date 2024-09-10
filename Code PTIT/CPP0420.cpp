#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int x;

bool compare(int a, int b) { return (abs(a - x) < abs(b - x)); }
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n >> x;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::stable_sort(a.begin(), a.end(), compare);
        for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
        std::cout << std::endl;
    }
}