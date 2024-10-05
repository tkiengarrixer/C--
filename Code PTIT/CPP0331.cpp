#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

std::string add(std::string &num1, std::string &num2) {
    std::string result;
    int len1 = num1.size();
    int len2 = num2.size();
    int carry = 0;

    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    int maxLen = len1 > len2 ? len1 : len2;
    std::vector<int> a(maxLen, 0);
    std::vector<int> b(maxLen, 0);
    std::vector<int> c;

    for (int i = 0; i < len1; ++i) a[i] = num1[i] - '0';
    for (int i = 0; i < len2; ++i) b[i] = num2[i] - '0';

    for (int i = 0; i < maxLen; ++i) {
        int sum = a[i] + b[i] + carry;
        c.push_back(sum % 10);
        carry = sum / 10;
    }

    if (carry) c.push_back(carry);

    std::reverse(c.begin(), c.end());
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    for (int i = 0; i < c.size(); ++i) result.push_back(c[i] + '0');
    return result;
}

bool isSumString(std::string &s) {
    int len = s.size();

    for (int i = 1; i <= len / 2; ++i) {
        for (int j = 1; j <= len / 2; ++j) {
            std::string s1 = s.substr(0, i);
            std::string s2 = s.substr(i, j);
            std::string s3 = add(s1, s2);
            int start = i + j;
            int s3Size = s3.size();
            if (s.find(s3, start) == start && start + s3Size == len) return true;
        }
    }
    return false;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;

        if (isSumString(s)) std::cout << "Yes";
        else std::cout << "No";
        std::cout << std::endl;
    }
}