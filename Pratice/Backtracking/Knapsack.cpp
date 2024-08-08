#include <cmath>
#include <iostream>
#include <vector>

int n;
long long s;
std::vector<std::pair<long long, long long>> a;
long long result = 0;

void backTrack(int i, long long currentValue, long long currentWeight) {
    if (i == n) {
        result = std::max(result, currentValue);
        return;
    }
    backTrack(i + 1, currentValue, currentWeight);  // Khong chon mon do thu i
    if (currentWeight + a[i].first <= s) {          // Chon mon do thu i
        backTrack(i + 1, currentValue + a[i].second,
                  currentWeight + a[i].first);
    }
}

int main() {
    std::cin >> n >> s;
    a.resize(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i].first >> a[i].second;
    backTrack(0, 0, 0);
    std::cout << result;
}