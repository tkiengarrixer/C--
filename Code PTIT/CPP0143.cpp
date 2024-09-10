#include <cmath>
#include <iostream>
#include <vector>

std::vector<long long> fibo(93);

void fibonacci() {
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 93; ++i) fibo[i] = fibo[i - 1] + fibo[i - 2];
}

int main() {
    fibonacci();
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << fibo[n] << std::endl;
    }
}