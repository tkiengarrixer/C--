#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

long long n, r, b, g;
std::vector<long long> fact(21);

void factorial() {
    fact[0] = 1;
    for (long long i = 1; i < 21; ++i) {
        fact[i] = fact[i - 1] * i;
    }
}

long long combination(long long n, long long k) {
    return fact[n] / (fact[k] * fact[n - k]);
}

int main() {
    factorial();
    long long t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> r >> b >> g;
        long long left = n - (r + b + g);
        long long result = 0;

        for (long long i = 0; i <= left; ++i) {
            for (long long j = 0; j <= left - i; ++j) {
                long long k = left - (i + j);
                result += combination(n, i + r) * // Số cách chọn r chỗ và i chỗ còn lại cho màu đỏ
                          combination(n - (i + r), j + b) * // Số cách chọn b chỗ và j chỗ còn lại cho màu xanh dương sau khi chọn màu đỏ
                          combination(n - (i + r + j + b), k + g); // Số cách chọn g chỗ và k chỗ còn lại cho màu xanh lá sau khi chọn màu đỏ và xanh dương
            }
        }

        std::cout << result << std::endl;
    }
}