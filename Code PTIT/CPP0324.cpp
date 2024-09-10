#include <iostream>
#include <string>

long long solve(long long a, long long b, long long mod) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

long long mod(std::string s, long long b, long long m) {
    long long result = 0;
    for (long long j = 0; j < s.size(); ++j) {
        result = (result * 10 + (s[j] - '0')) % m;
    }
    return solve(result, b, m);
}

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        std::string s;
        long long b, m;
        std::cin >> s >> b >> m;
        std::cout << mod(s, b, m) << std::endl;
    }
}