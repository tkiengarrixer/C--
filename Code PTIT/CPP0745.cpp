#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

std::vector<long long> fibo(1001);

void fibonacci() {
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 1001; ++i)
        fibo[i] = (fibo[i - 1] % MOD + fibo[i - 2] % MOD) % MOD;
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