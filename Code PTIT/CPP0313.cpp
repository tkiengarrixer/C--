#include <iostream>
#include <string>

int main() {
    std::string s;
    std::string t;
    std::getline(std::cin, s);
    std::getline(std::cin, t);
    s.erase(s.find(t), t.size() + 1);
    std::cout << s;
}