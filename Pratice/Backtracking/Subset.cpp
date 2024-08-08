#include <cmath>
#include <iostream>
#include <vector>

long long n, k;
std::vector<int> a;

void printResult() {
    for (int i = 1; i <= k; ++i) std::cout << a[i] << " ";
    std::cout << std::endl;
}

void backTrack(int index) {
    for (int i = a[index - 1] + 1; i <= n - k + index; ++i) {
        a[index] = i;
        if (index == k)
            printResult();
        else
            backTrack(index + 1);
    }
}

int main() {
    std::cin >> n >> k;
    a.resize(k + 1);
    backTrack(1);
}