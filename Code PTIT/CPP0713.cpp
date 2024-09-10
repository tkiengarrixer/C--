#include <iostream>
#include <vector>

int n;
std::vector<int> a;
std::vector<bool> used;

void print() {
    for (int i = 0; i < n; ++i) std::cout << a[i];
    std::cout << " ";
}

void backtrack(int num) {
    if (num == n) {
        print();
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            a[num] = i;
            backtrack(num + 1);
            used[i] = false;
        }
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        a.resize(n);
        used.resize(n + 1, false);
        backtrack(0);
        std::cout << std::endl;
    }
}