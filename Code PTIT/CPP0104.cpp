#include <iostream>

long long fact(long long n) {
    long long result = 1;
    for (long long i = 1; i <= n; ++i) result *= i;
    return result;
}

int main() {
    long long n;
    std::cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n; ++i) sum += fact(i);
    std::cout << sum;
}