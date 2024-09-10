#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::getline(std::cin, s);
    for (int i = 0; i < s.size(); ++i) s[i] = tolower(s[i]);
    std::stringstream ss(s);
    std::string word;
    std::vector<std::string> a;
    while (ss >> word) {
        a.push_back(word);
    }
    for (int i = 0; i < a.size() - 1; ++i) {
        a[i][0] = toupper(a[i][0]);
    }
    for (int i = 0; i < a.size() - 1; ++i) {
        std::cout << a[i];
        if (i < a.size() - 2) std::cout << " ";
    }
    for (int i = 0; i < a[a.size() - 1].size(); ++i) {
        a[a.size() - 1][i] = toupper(a[a.size() - 1][i]);
    }
    std::cout << ", " << a[a.size() - 1];
}