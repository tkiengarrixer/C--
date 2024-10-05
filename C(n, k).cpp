#include <algorithm>
#include <cmath>
#include <iostream>

const long long MAX = 1e5;
const long long P = 1e9 + 7;
long long fact[MAX], invFact[MAX];

long long myPow(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 != 0) result = (result * a) % P;
        a = (a * a) % P;
        b /= 2;
    }
    return result;
}

void factorial() {
    fact[0] = 1;
    for (long long i = 1; i <= MAX; ++i) {
        fact[i] = (fact[i - 1] * i) % P;
    }
}

void inverse() {
    invFact[MAX] = myPow(fact[MAX], P - 2);
    for (long long i = MAX; i >= 1; --i) {
        invFact[i - 1] = (invFact[i] * i) % P;
    }
}

long long combination(long long n, long long k) {
    return (fact[n] * invFact[k] % P * invFact[n - k] % P) % P;
}

int main() {
    factorial();
    inverse();
    int t;
    std::cin >> t;
    while (t--) {
        long long n, r;
        std::cin >> n >> r;
        std::cout << combination(n, r) << std::endl;
    }
}