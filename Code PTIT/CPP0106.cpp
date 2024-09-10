#include <iostream>
#include <string>

bool check(std::string &s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) return false;
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
            std::cout << "YES" << "\n";
        else
            std::cout << "NO" << "\n";
    }
    return 0;
}