#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        int count = 0;
        int lim = a[n - 1] - a[0];
        for (int i = 1; i <= lim; ++i) {
            bool flag = true;
            for (int j = 1; j < n; ++j) {
                if ((a[j] - a[0]) % i != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) ++count;
        }
        std::cout << count << std::endl;
    }
}