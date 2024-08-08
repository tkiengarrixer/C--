#include <cmath>
#include <iostream>
#include <vector>

long long n, k;
std::vector<int> a;
std::vector<bool> used;

void printResult() {
    for (int i = 0; i < k; ++i) std::cout << a[i] << " ";
    std::cout << std::endl;
}

void backTrack(int index) {
    if (index == k) {
        printResult();
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            a[index] = i;
            backTrack(index + 1);
            used[i] = false;
        }
    }
}

int main() {
    std::cin >> n >> k;
    a.resize(k);
    used.resize(n + 1, false);
    backTrack(0);
}