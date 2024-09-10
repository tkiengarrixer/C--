#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, p;
        std::cin >> n >> p;
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            int temp = i;
            while (temp % p == 0) {
                ++count;
                temp /= p;
            }
        }
        std::cout << count << std::endl;
    }
}