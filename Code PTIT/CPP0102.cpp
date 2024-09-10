#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        char c;
        std::cin >> c;
        if (c >= 65 && c <= 90)
            std::cout << char(c + 32);
        else
            std::cout << char(c - 32);
        std::cout << "\n";
    }
    return 0;
}