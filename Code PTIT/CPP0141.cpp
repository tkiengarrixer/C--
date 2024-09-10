#include <iostream>
#include <vector>

std::vector<long long> fibo(92);

void fibonacci() {
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 92; ++i) fibo[i] = fibo[i - 2] + fibo[i - 1];
}
int main() {
    fibonacci();
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        bool flag = false;
        for (int i = 0; i < 92; ++i) {
            if (fibo[i] == n) {
                std::cout << "YES";
                flag = true;
                break;
            }
        }
        if (!flag) std::cout << "NO";
        std::cout << std::endl;
    }
}