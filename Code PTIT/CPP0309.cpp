#include <iostream>
#include <sstream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin.ignore();
        std::getline(std::cin, s);
        std::stringstream ss(s);
        std::string word;
        int count = 0;
        while (ss >> word) ++count;
        std::cout << count << std::endl;
    }
}