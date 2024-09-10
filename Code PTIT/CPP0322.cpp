#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string add(std::string &num1, std::string &num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    int len = len1 > len2 ? len1 : len2;
    for (int i = len1; i < len; ++i) num1.push_back('0');
    for (int i = len2; i < len; ++i) num2.push_back('0');
    std::string result;
    int carry = 0;

    for (int i = 0; i < len; ++i) {
        int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry > 0) result.push_back(carry + '0');

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
        std::cout << add(num1, num2) << std::endl;
    }
}