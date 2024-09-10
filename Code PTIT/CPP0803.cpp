#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main() {
    std::ifstream input("DATA.in");
    std::map<int, int> map;
    int num;

    while (input >> num) {
        ++map[num];
    }
    input.close();

    for (auto pair : map) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}