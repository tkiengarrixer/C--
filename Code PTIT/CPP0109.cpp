#include <cmath>
#include <iostream>
#include <string>
#include <vector>

bool check(long long n) {
    std::vector<long long> a;
    while (n != 0) {
        a.push_back(n % 10);
        n /= 10;
    }
    long long countOdd = 0;
    long long countEven = 0;
    for (long long i = 0; i < a.size(); ++i) {
        if (a[i] % 2 == 0)
            ++countEven;
        else
            ++countOdd;
    }
    if (countOdd == countEven)
        return true;
    else
        return false;
}

int main() {
    long long n;
    std::cin >> n;
    int count = 0;
    for (long long i = pow(10, n - 1); i <= pow(10, n) - 1; ++i) {
        if (check(i)) {
            std::cout << i << " ";
            ++count;
        }
        if (count == 10) {
            std::cout << "\n";
            count = 0;
        }
    }
}