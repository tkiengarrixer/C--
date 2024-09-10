#include <cmath>
#include <iostream>

bool isPrime(long long n) {
    if (n < 2)
        return false;
    else
        for (int i = 2; i <= sqrt(n); ++i)
            if (n % i == 0) return false;
    return true;
}
int main() {
    long long n;
    std::cin >> n;
    if (isPrime(n))
        std::cout << "YES";
    else
        std::cout << "NO";
}