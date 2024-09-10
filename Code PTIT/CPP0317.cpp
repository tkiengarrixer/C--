#include <iostream>
#include <string>

bool check(std::string& s) {
    int len = s.size();
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - i - 1] || (s[i] - '0') % 2 != 0) return false;
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
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << std::endl;
    }
}