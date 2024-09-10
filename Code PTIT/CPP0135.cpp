#include <cmath>
#include <iostream>
#include <vector>

std::vector<bool> prime(1000001, true);
std::vector<int> three;

void sieve() {
    prime[0] = prime[1] = false;
    for (int i = 2; i <= 1000; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < 1000001; j += i) prime[j] = false;
        }
    }
}

void process() {
    sieve();
    for (int i = 2; i <= 1000; ++i) {
        if (prime[i]) three.push_back(i * i);
    }
}

int main() {
    process();
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 0; i < three.size(); ++i) {
            if (three[i] <= n)
                std::cout << three[i] << " ";
            else
                break;
        }
        std::cout << std::endl;
    }
}