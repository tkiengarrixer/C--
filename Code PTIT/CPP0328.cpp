#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int countDivisibleByDiv(std::string num, int div) {
    int n = num.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum = sum * 10 + (num[j] - '0');
            sum %= div;
            if (sum == 0) ++count;
        }
    }
    return count;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string num;
        std::cin >> num;
        int count = 0;
        std::cout << countDivisibleByDiv(num, 8) - countDivisibleByDiv(num, 24)
                  << std::endl;
    }
}