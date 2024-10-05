#include <cmath>
#include <iostream>
#include <map>
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

std::map<long long, long long> primeFactors(long long n) {
    std::map<long long, long long> fact;
    long long lim = sqrt(n);

    for (long long i = 0; i < prime.size(); ++i) {
        if (prime[i] > lim) break;
        while (n % prime[i] == 0) {
            ++fact[prime[i]];
            n /= prime[i];
        }
        lim = sqrt(n);
    }
    if (n > 1) ++fact[n];
    
    return fact;
}

int main() {
    sieve();
    long long t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        std::map<long long, long long> map = primeFactors(n);

        for (auto it : map) {
            std::cout << it.first << " " << it.second << std::endl;
        }

        std::cout << std::endl;
    }
}
