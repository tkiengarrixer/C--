#include <iostream>
#include <string>

bool check(const std::string& n) {
    int mod = 0;
    for (char bit : n) {
        mod = (mod * 2 + (bit - '0')) % 5;
    }
    return mod == 0;
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    while (t--) {
        std::string n;
        std::getline(std::cin, n);
        if (check(n))
            std::cout << "Yes";
        else
            std::cout << "No";
        std::cout << std::endl;
    }

    return 0;
}
