#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    std::unordered_map<char, int> freq;
    std::unordered_map<char, int> tempFreq;
    std::vector<std::unordered_map<char, int>> mapList;

    for (int i = 0; i < s.size(); ++i) {
        ++freq[s[i]];
        ++tempFreq[s[i]];

        if (i == s.size() - 1 || s[i + 1] != s[i]) {
            mapList.push_back(tempFreq);
            tempFreq.clear();
        }
    }

    if (freq['B'] == 1) {
        std::cout << "1";
        return 0;
    }

    int countB = 0, countA = 0;
    for (const auto& subMap : mapList) {
        if (subMap.find('B') != subMap.end() && subMap.at('B') == 1) ++countB;
        if (subMap.find('A') != subMap.end()) ++countA;
    }

    if (countA + countB == mapList.size()) {
        std::cout << countB;
        return 0;
    }

    std::cout << mapList.size();
    return 0;
}
