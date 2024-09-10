#include <cmath>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b, c;
        std::cin >> a >> b >> c;
        long long result = 0;
        a %= c;
        while (b > 0) {
            if (b % 2 != 0) {
                result = (result + a) % c;
            }
            a = (a * 2) % c;
            b /= 2;
        }
        std::cout << result << std::endl;
    }
}