#include <iostream>
#include <map>
#include <string>

bool subString(const std::string& sub, const std::string& s2) {
    std::map<char, int> freqS2;
    for (char c : s2) ++freqS2[c];

    for (char c : sub) {
        if (freqS2.find(c) != freqS2.end()) {
            --freqS2[c];
            if (freqS2[c] == 0) freqS2.erase(c);
        }
    }
    return freqS2.empty();
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s1, s2;
        std::cin >> s1 >> s2;

        int minLength = s1.size() + 1;
        std::string minSubString = "-1";

        for (int i = 0; i < s1.size(); ++i) {
            for (int j = i; j < s1.size(); ++j) {
                std::string sub = s1.substr(i, j - i + 1);
                if (subString(sub, s2)) {
                    if (sub.size() < minLength) {
                        minLength = sub.size();
                        minSubString = sub;
                    }
                }
            }
        }

        std::cout << minSubString << std::endl;
    }
}
