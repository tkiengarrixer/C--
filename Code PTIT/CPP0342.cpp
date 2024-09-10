#include <algorithm>
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
            if (isdigit(s[i])) {
                sum += (s[i] - '0');
                s[i] = ' ';
            }
        }
        std::string result;
        std::stringstream ss(s);
        std::string word;
        while (ss >> word) {
            result += word;
        }
        std::sort(result.begin(), result.end());
        result += std::to_string(sum);
        std::cout << result << std::endl;
    }
}