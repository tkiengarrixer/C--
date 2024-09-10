#include <cmath>
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
        int n;
        std::cin >> n;
        std::vector<int> result;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            for (int i = 0; i < 92; ++i) {
                if (fibo[i] == x) {
                    result.push_back(x);
                    break;
                }
            }
        }
        for (int num : result) std::cout << num << " ";
        std::cout << std::endl;
    }
}