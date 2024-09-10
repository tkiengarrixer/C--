#include <iostream>
#include <sstream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (!isdigit(s[i])) s[i] = ' ';
        }
        int max = -1e9;
        std::stringstream ss(s);
        std::string num;
        while (ss >> num) {
            int number = std::stoi(num);
            max = std::max(number, max);
        }
        std::cout << max << std::endl;
    }
}