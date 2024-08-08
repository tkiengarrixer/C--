#include <cmath>
#include <iostream>
#include <vector>

std::vector<long long> a;
long long n, k;

bool backTrack(long long index, long long currentSum) {
    if (currentSum == k) return true;
    if (index >= n || currentSum > k) return false;
    if (backTrack((index + 1), currentSum)) return true;
    if (backTrack(index + 1, currentSum + a[index])) return true;
    return false;
}

int main() {
    std::cin >> n >> k;
    a.resize(n);
    for (long long i = 0; i < n; ++i) std::cin >> a[i];
    if (backTrack(0, 0))
        std::cout << "YES";
    else
        std::cout << "NO";
}