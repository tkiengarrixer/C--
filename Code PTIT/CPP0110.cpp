#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        s.erase(s.find("084"), 3);
        std::cout << s << std::endl;
    }
    return 0;
}