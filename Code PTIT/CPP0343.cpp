#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool check(std::vector<int>& a) {
    int numOfOdd = 0, numOfEven = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] % 2 == 0)
            ++numOfEven;
        else
            ++numOfOdd;
    }
    if ((a.size() % 2 == 0 && numOfEven > numOfOdd) ||
        (a.size() % 2 != 0 && numOfOdd > numOfEven))
        return true;
    else
        return false;
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    while (t--) {
        std::string s;
        std::getline(std::cin, s);
        std::stringstream ss(s);
        std::string word;
        std::vector<int> a;
        while (ss >> word) {
            a.push_back(std::stoi(word));
        }
        if (check(a))
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << std::endl;
    }
}