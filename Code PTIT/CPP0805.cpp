#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    std::ifstream input1("DATA1.in");
    std::ifstream input2("DATA2.in");
    std::set<std::string> set1;
    std::set<std::string> set2;
    std::string word;

    while (input1 >> word) {
        for (int i = 0; i < word.size(); ++i) word[i] = tolower(word[i]);
        set1.insert(word);
    }
    while (input2 >> word) {
        for (int i = 0; i < word.size(); ++i) word[i] = tolower(word[i]);
        set2.insert(word);
    }

    std::vector<std::string> intersecSet;
    std::vector<std::string> unionSet;

    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                          std::back_inserter(intersecSet));
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   std::back_inserter(unionSet));

    for (int i = 0; i < unionSet.size(); ++i) std::cout << unionSet[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < intersecSet.size(); ++i)
        std::cout << intersecSet[i] << " ";
}