#include <iostream>
#include <string>

bool isLucky(int n) {
    while (n > 10) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }
    return n == 9;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) sum += (s[i] - '0');
        if (isLucky(sum))
            std::cout << "1";
        else
            std::cout << "0";
        std::cout << std::endl;
    }
}