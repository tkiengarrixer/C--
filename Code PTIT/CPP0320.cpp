#include <iostream>
#include <string>
#include <vector>

int check(std::string &s) {
    std::vector<int> check(10, 0);
    int len = s.size();
    if (s[0] == '0') return -1;
    for (int i = 0; i < len; ++i) {
        if (isalpha(s[i])) return -1;
        check[s[i] - '0']++;
    }
    for (int i = 0; i < 10; ++i)
        if (check[i] == 0) return 0;
    return 1;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        if (check(s) == -1)
            std::cout << "INVALID";
        else if (check(s))
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << std::endl;
    }
}