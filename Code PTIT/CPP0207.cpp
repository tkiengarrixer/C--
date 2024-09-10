#include <algorithm>
#include <iostream>
#include <vector>

void rotate(std::vector<int> &a, int d) {
    int n = a.size();
    d = d % n;
    std::reverse(a.begin(), a.begin() + d);
    std::reverse(a.begin() + d, a.end());
    std::reverse(a.begin(), a.end());
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, d;
        std::cin >> n >> d;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        rotate(a, d);
        for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
        std::cout << std::endl;
    }
    return 0;
}
