#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i == n) {
            for (int j = 1; j <= 2 * n - 1; ++j) {
                if (j % 2 == 0)
                    std::cout << " ";
                else
                    std::cout << "*";
            }
        }
        for (int j = n - i; j >= 1; --j) std::cout << " ";
        for (int j = 1; j <= 2 * i - 1; ++j) {
            if ((j == 1 || j == 2 * i - 1) && i != n)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}