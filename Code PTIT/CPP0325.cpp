#include <iostream>
#include <string>

bool check(std::string& s) {
    int len = s.size();
    int sumOfOdd = 0, sumOfEven = 0;
    for (int i = 0; i < len; ++i) {
        if (i % 2 == 0)
            sumOfOdd += (s[i] - '0');
        else
            sumOfEven += (s[i] - '0');
    }
    int delta = abs(sumOfOdd - sumOfEven);
    return (delta % 11 == 0 || delta == 0);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string n;
        std::cin >> n;
        if (check(n))
            std::cout << "1";
        else
            std::cout << "0";
        std::cout << std::endl;
    }
}