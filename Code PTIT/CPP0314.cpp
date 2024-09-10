#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::map<std::string, int> freq;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::getline(std::cin, s);
        ++freq[s];
    }
    std::cout << freq.size();
}