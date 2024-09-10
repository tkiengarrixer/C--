#include <fstream>
#include <iostream>
#include <set>
#include <string>

int main() {
    std::ifstream input("VANBAN.in");
    std::set<std::string> set;
    std::string word;

    while (input >> word) {
        for (int i = 0; i < word.size(); ++i) word[i] = tolower(word[i]);
        set.insert(word);
    }
    for (auto word : set) {
        std::cout << word << std::endl;
    }
}