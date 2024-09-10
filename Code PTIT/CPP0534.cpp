#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

bool isPalindrome(const std::string &s) {
    int len = s.size();
    if (len < 2) return false;
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - i - 1]) return false;
    }
    return true;
}

bool compare(const std::pair<std::string, int> &a,
             const std::pair<std::string, int> &b) {
    if (a.first.size() > b.first.size()) return true;
    if (a.first.size() < b.first.size()) return false;
    return a.first > b.first;
}

int main() {
    std::string num;
    std::map<std::string, int> freq;

    while (std::cin >> num) {
        if (isPalindrome(num)) freq[num]++;
    }
    std::vector<std::pair<std::string, int>> temp(freq.begin(), freq.end());
    std::sort(temp.begin(), temp.end(), compare);
    for (const auto &it : temp) {
        std::cout << it.first << " " << it.second << std::endl;
    }
    return 0;
}
