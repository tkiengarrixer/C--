#include <cmath>
#include <iostream>

void fact(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        int count = 0;
        while (n % i == 0) {
            ++count;
            n /= i;
        }
        if (count != 0) {
            std::cout << i << " " << count << " ";
        }
    }
    if (n > 1) std::cout << n << " " << "1";
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        fact(n);
        std::cout << std::endl;
    }
}