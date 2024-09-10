#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        std::unordered_map<char, int> freq;
        std::vector<char> order;
        for (int i = 0; i < s.size(); ++i) {
            if (freq[s[i]] == 0) order.push_back(s[i]);
            ++freq[s[i]];
        }
        for (int i = 0; i < order.size(); ++i) {
            std::cout << order[i] << freq[order[i]];
        }
        std::cout << std::endl;
    }
}