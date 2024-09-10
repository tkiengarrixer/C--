#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

bool compare(std::string a, std::string b) {
    std::string ab = a + b;
    std::string ba = b + a;
    return ab > ba;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::string> a;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            a.push_back(std::to_string(x));
        }
        std::sort(a.begin(), a.end(), compare);
        for (auto it : a) {
            std::cout << it;
        }
        std::cout << std::endl;
    }
}
