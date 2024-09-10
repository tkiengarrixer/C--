#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, m;
        std::cin >> a >> m;
        bool flag = false;
        for (int i = 0; i < m; ++i) {
            if (i * a % m == 1) {
                std::cout << i;
                flag = true;
                break;
            }
        }
        if (!flag) std::cout << "-1";
        std::cout << std::endl;
    }
}