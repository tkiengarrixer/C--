#include <iostream>
#include <string>

long long mod(std::string s, long long n) {
    long long result = 0;
    for (int i = 0; i < s.size(); ++i) {
        result = (result * 10 + (s[i] - '0')) % n;
    }
    return result;
}

long long GCD(std::string b, long long a) {
    long long bNum = mod(b, a);
    while (a != 0) {
        long long r = bNum % a;
        bNum = a;
        a = r;
    }
    return bNum;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        long long m;
        std::cin >> m >> s;
        std::cout << GCD(s, m) << std::endl;
    }
}