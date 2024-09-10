#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    while (t--) {
        std::string s;
        std::getline(std::cin, s);
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> result;
        while (ss >> word) {
            result.push_back(word);
        }
        std::reverse(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i) std::cout << result[i] << " ";
        std::cout << std::endl;
    }
}