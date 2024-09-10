#include <iostream>
#include <vector>

bool check(long long n) {
    std::vector<int> a;
    while (n != 0) {
        a.push_back(n % 10);
        n /= 10;
    }
    for (int i = 0; i < a.size() - 1; ++i) {
        if (abs(a[i] - a[i + 1]) != 1) return false;
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        if (check(n))
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
}