#include <cmath>
#include <iostream>
#include <vector>

bool isMountain(std::vector<int> &a, int l, int r) {
    int index = -1;
    int max = -1e9;
    for (int i = l; i <= r; ++i) {
        if (a[i] >= max) {
            max = a[i];
            index = i;
        }
    }
    for (int i = l; i < index; ++i) {
        if (a[i] > a[i + 1]) return false;
    }
    for (int i = index; i < r; ++i) {
        if (a[i] < a[i + 1]) return false;
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int l, r;
        std::cin >> l >> r;
        if (isMountain(a, l, r))
            std::cout << "Yes";
        else
            std::cout << "No";
        std::cout << std::endl;
    }
}