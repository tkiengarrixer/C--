#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int n = s.length();
        std::vector<int> result;
        int count = 1;
        for (int i = 0; i <= n; ++i) {
            result.push_back(count);
            ++count;
            if (i == n || s[i] == 'I') {
                for (int j = result.size() - 1; j >= 0; --j) {
                    std::cout << result[j];
                }
                result.clear();
            }
        }
        std::cout << std::endl;
    }
}
