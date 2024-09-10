#include <iostream>
#include <set>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        int k;
        std::cin >> s >> k;
        std::set<char> set;
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                set.insert(s[j]);
                if (set.size() == k)
                    ++result;
                else if (set.size() > k)
                    break;
            }
            set.clear();
        }
        std::cout << result << std::endl;
    }
}