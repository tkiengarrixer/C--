#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int a[] = {5, 20, 38, 50, 38, 20, 8, 5, 0};
        std::cout << a[n - 1] << std::endl;
    }
}