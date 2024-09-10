#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string s;
        std::cin >> n;
        std::cin.ignore();
        std::getline(std::cin, s);
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> result;
        while (ss >> word) {
            word[0] = toupper(word[0]);
            for (int i = 1; i < word.size(); ++i) word[i] = tolower(word[i]);
            result.push_back(word);
        }
        int len = result.size();
        if (n == 1) {
            std::cout << result[len - 1] << " ";
            for (int i = 0; i < len - 1; ++i) std::cout << result[i] << " ";
        } else {
            for (int i = 1; i < len; ++i) std::cout << result[i] << " ";
            std::cout << result[0];
        }
        std::cout << std::endl;
    }
}