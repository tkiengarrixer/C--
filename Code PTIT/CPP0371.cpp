#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.size(); ++i) s[i] = tolower(s[i]);
    std::string temp;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' &&
            s[i] != 'u' && s[i] != 'y') {
            temp += '.';
            temp += s[i];
        }
    }
    std::cout << temp;
}