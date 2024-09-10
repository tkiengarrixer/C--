#include <iostream>
#include <map>
#include <string>

bool check(std::string &s) {
    int len = s.size();
    std::map<char, int> map;
    for (int i = 0; i < len; ++i) {
        ++map[s[i]];
    }
    for (auto pair : map) {
        if (pair.second > (len + 1) / 2) return false;
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        if (check(s))
            std::cout << "1";
        else
            std::cout << "0";
        std::cout << std::endl;
    }
}