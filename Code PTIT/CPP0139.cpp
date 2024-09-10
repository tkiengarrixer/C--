#include <cmath>
#include <iostream>
#include <string>
#include <vector>

const long long MAX = 1e7;
std::vector<bool> isPrime(MAX, true);
std::vector<long long> prime;

void sieve() {
    isPrime[0] = isPrime[1] = false;
    long long lim = sqrt(MAX);
    for (long long i = 2; i <= lim; ++i) {
        if (isPrime[i]) {
            prime.push_back(i);
            for (long long j = i * i; j < MAX; j += i) isPrime[j] = false;
        }
    }
    for (long long i = lim + 1; i < MAX; ++i) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }
}

bool isSmith(long long n) {
    if (isPrime[n]) return false;

    long long sumFactors = 0;
    long long temp = n;
    long long lim = sqrt(n);

    for (long long i = 0; i < prime.size(); ++i) {
        if (prime[i] > lim) break;
        while (n % prime[i] == 0) {
            long long factor = prime[i];
            while (factor != 0) {
                sumFactors += factor % 10;
                factor /= 10;
            }
            n /= prime[i];
        }
        lim = sqrt(n);
    }

    if (n > 1) {
        while (n != 0) {
            sumFactors += n % 10;
            n /= 10;
        }
    }

    long long sumDigits = 0;
    while (temp != 0) {
        sumDigits += temp % 10;
        temp /= 10;
    }

    return sumFactors == sumDigits;
}

int main() {
    sieve();
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (isSmith(n))
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << std::endl;
    }
}