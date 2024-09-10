#include <iostream>
#include <string>

long long mod(std::string s, long long n) {
    long long result = 0;
    for (int i = 0; i < s.size(); ++i) {
        result = (result * 10 + (s[i] - '0')) % n;
    }
    return result;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        long long m;
        std::cin >> s >> m;
        std::cout << mod(s, m) << std::endl;
    }
}