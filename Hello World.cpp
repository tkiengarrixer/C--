#include <bits/stdc++.h>
using namespace std;

unsigned long long factorial(unsigned long long n) {
    unsigned long long result = 1;
    for (unsigned long long i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

unsigned long long numberOfWays(unsigned long long k) {
    vector<int> factors;
    for (int i = 2; i <= sqrt(k); ++i) {
        while (k % i == 0) {
            factors.push_back(i);
            k /= i;
        }
    }
    if (k > 1) {
        factors.push_back(k);
    }

    map<int, int> freq;
    for (int factor : factors) {
        freq[factor]++;
    }

    unsigned long long total = factorial(factors.size());
    for (const auto& entry : freq) {
        total /= factorial(entry.second);
    }
    return total;
}

unsigned long long findMinK(unsigned long long n) {
    unsigned long long k = 1;
    while (true) {
        if (numberOfWays(k) == n) {
            return k;
        }
        k++;
        if (k > 1000000) break;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;
        if (n == 1) {
            cout << n << " " << 2 << "\n";
        } else {
            unsigned long long k = findMinK(n);
            cout << n << " " << k << "\n";
        }
    }

    return 0;
}
