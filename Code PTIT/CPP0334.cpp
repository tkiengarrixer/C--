#include <iostream>
#include <sstream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (!isdigit(s[i])) s[i] = ' ';
        }
        std::stringstream ss(s);
        std::string num;
        while (ss >> num) {
            sum += std::stoi(num);
        }
        std::cout << sum << std::endl;
    }
}