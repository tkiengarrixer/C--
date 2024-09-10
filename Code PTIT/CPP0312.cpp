#include <iostream>
#include <string>
#include <unordered_set>

bool check(std::string& s, int k) {
    std::unordered_set<char> us;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') us.insert(s[i]);
    }
    int miss = 26 - us.size();
    return miss <= k;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        int k;
        std::cin >> s;
        std::cin >> k;
        if (check(s, k))
            std::cout << "1";
        else
            std::cout << "0";
        std::cout << std::endl;
    }
}