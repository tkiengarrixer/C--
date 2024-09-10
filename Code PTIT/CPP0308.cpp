#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::unordered_map<char, int> duplicate;
        std::vector<char> order;
        std::cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (duplicate[s[i]] == 0) order.push_back(s[i]);
            ++duplicate[s[i]];
        }
        for (int i = 0; i < order.size(); ++i) {
            if (duplicate[order[i]] < 2) std::cout << order[i];
        }
        std::cout << std::endl;
    }
}