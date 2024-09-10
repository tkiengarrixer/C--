#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

std::set<std::string> get(std::string &s) {
    std::set<std::string> set;
    std::stringstream ss(s);
    std::string word;
    while (ss >> word) {
        set.insert(word);
    }
    return set;
}
int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    while (t--) {
        std::string s;
        std::string t;
        std::getline(std::cin, s);
        std::getline(std::cin, t);
        std::set<std::string> set1 = get(s);
        std::set<std::string> set2 = get(t);
        std::vector<std::string> result;
        std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                            std::back_inserter(result));
        for (int i = 0; i < result.size(); ++i) std::cout << result[i] << " ";
        std::cout << std::endl;
    }
}