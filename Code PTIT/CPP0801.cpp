#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream input("PTIT.in");
    std::ofstream output("PTIT.out");

    std::string line;
    while (std::getline(input, line)) {
        output << line << std::endl;
    }
    return 0;
}
