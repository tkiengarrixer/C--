#include <iostream>
#include <string>

char mapping(char c) {
    if (c == 'A' || c == 'B' || c == 'C')
        return '2';
    else if (c == 'D' || c == 'E' || c == 'F')
        return '3';
    else if (c == 'G' || c == 'H' || c == 'I')
        return '4';
    else if (c == 'J' || c == 'K' || c == 'L')
        return '5';
    else if (c == 'M' || c == 'N' || c == 'O')
        return '6';
    else if (c == 'P' || c == 'Q' || c == 'R' || c == 'S')
        return '7';
    else if (c == 'T' || c == 'U' || c == 'V')
        return '8';
    else
        return '9';
}
std::string convert(std::string &s) {
    for (int i = 0; i < s.size(); ++i) s[i] = toupper(s[i]);
    std::string result;
    for (int i = 0; i < s.size(); ++i) {
        result.push_back(mapping(s[i]));
    }
    return result;
}

bool check(std::string &s) {
    std::string num = convert(s);
    for (int i = 0; i < num.size() / 2; ++i) {
        if (num[i] != num[num.size() - i - 1]) return false;
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