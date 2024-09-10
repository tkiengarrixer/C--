#include <algorithm>
#include <iostream>
#include <string>

std::string sub(std::string num1, std::string num2) {
    int len1 = num1.size();
    int len2 = num2.size();

    if (len1 < len2 || (len1 == len2 && num1 < num2)) {
        std::swap(num1, num2);
        std::swap(len1, len2);
    }
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    for (int i = len2; i < len1; ++i) num2.push_back('0');
    std::string result;
    int borrow = 0;

    for (int i = 0; i < len1; ++i) {
        int diff = (num1[i] - '0') - (num2[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else
            borrow = 0;
        result.push_back(diff + '0');
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string num1;
        std::string num2;
        std::cin >> num1 >> num2;
        std::cout << sub(num1, num2) << std::endl;
    }
}