#include <iostream>
#include <string>

std::string first = {"A B B A D C C A B D C C A B D"};
std::string second = {"A C C A B C D D B B C D D B B"};
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string s;
        std::cin >> n;
        std::cin.ignore();
        std::getline(std::cin, s);
        double score = 0;
        if (n == 101) {
            for (int i = 0; i < s.size(); ++i) {
                if (isalpha(s[i]) && s[i] == first[i]) score += (double)2 / 3;
            }
        } else {
            for (int i = 0; i < s.size(); ++i) {
                if (isalpha(s[i]) && s[i] == second[i]) score += (double)2 / 3;
            }
        }
        printf("%.2lf\n", score);
    }
    return 0;
}