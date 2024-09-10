#include <algorithm>
#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b;
        std::cin >> a >> b;
        std::string num1 = std::to_string(a);
        std::string num2 = std::to_string(b);
        std::string temp1 = num1;
        std::string temp2 = num2;
        for (int i = 0; i < num1.size(); ++i) {
            if (num1[i] == '5') num1[i] = '6';
        }
        for (int i = 0; i < num2.size(); ++i) {
            if (num2[i] == '5') num2[i] = '6';
        }
        a = std::stoll(num1);
        b = std::stoll(num2);
        long long max = a + b;

        for (int i = 0; i < num1.size(); ++i) {
            if (temp1[i] == '6') temp1[i] = '5';
        }
        for (int i = 0; i < num2.size(); ++i) {
            if (temp2[i] == '6') temp2[i] = '5';
        }
        a = std::stoll(temp1);
        b = std::stoll(temp2);
        long long min = a + b;
        std::cout << min << " " << max << std::endl;
    }
}