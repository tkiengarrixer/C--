#include <bits/stdc++.h>

int x[100], n;
void printResult() {
    for (int i = 1; i <= n; ++i) std::cout << x[i];
    std::cout << std::endl;
}

void backTrack(int i) {
    for (int j = 0; j <= 1; ++j) {
        x[i] = j;
        if (i == n)
            printResult();
        else {
            backTrack(i + 1);
        }
    }
}

int main() {
    std::cin >> n;
    backTrack(1);
}