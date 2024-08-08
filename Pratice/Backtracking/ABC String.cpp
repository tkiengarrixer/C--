#include <bits/stdc++.h>

int n;
std::vector<char> x;

void printResult() {
    for (int i = 1; i <= n; ++i) std::cout << x[i];
    std::cout << std::endl;
}

void backTrack(int i) {
    if (i == n + 1) {
        printResult();
        return;
    }
    for (char c : {'A', 'B', 'C'}) {
        if (i == 1 || x[i - 1] != c) {
            x[i] = c;
            backTrack((i + 1));
        }
    }
}

int main() {
    std::cin >> n;
    x.resize(n + 1);
    backTrack(1);
}