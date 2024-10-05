#include <iostream>
#include <fstream>

int main() {
    std::ofstream print("troll.txt");
    for (int i = 1; i <= 2024; ++i) {
        for (int j = i; j < 2024 + i; ++j) print << j << " ";
        print << std::endl;
    }
    
    return 0;
}
