#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool isDifferent(std::string a, std::string b) {
    int count = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) ++count;
    }
    return count == 2;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        std::string temp = s;
        std::string result = "-1";

        while (std::prev_permutation(s.begin(), s.end())) {
            if (isDifferent(s, temp)) {
                result = s;
                break;
            }
        }

        if (result != "-1")
            std::cout << result;
        else
            std::cout << "-1";
        std::cout << std::endl;
    }
}