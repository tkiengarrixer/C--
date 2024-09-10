#include <iostream>
#include <string>
#include <vector>

bool isIncreasing(std::string &s) {
    if (s[5] < s[6] && s[6] < s[7] && s[7] < s[9] && s[9] < s[10])
        return true;
    else
        return false;
}

bool isEqual(std::string &s) {
    if (s[5] == s[6] && s[6] == s[7] && s[7] == s[9] && s[9] == s[10])
        return true;
    else
        return false;
}

bool isEqual2(std::string &s) {
    if (s[5] == s[6] && s[6] == s[7] && s[9] == s[10])
        return true;
    else
        return false;
}

bool isLucky(std::string &s) {
    if ((s[5] == '6' || s[5] == '8') && (s[6] == '6' || s[6] == '8') &&
        (s[7] == '6' || s[7] == '8') && (s[9] == '6' || s[9] == '8') &&
        (s[10] == '6' || s[10] == '8'))
        return true;
    else
        return false;
}

bool check(std::string &s) {
    if (isIncreasing(s) || isEqual(s) || isEqual2(s) || isLucky(s))
        return true;
    else
        return false;
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