#include <iostream>
#include <vector>

int n;
std::vector<int> a;

void print() {
    for (int i = 0; i < n; ++i) std::cout << a[i];
    std::cout << " ";
}

void backtrack(int i) {
    for (int j = 0; j <= 1; ++j) {
        a[i] = j;
        if (i == n - 1) {
            print();
        } else
            backtrack(i + 1);
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        a.resize(n);
        backtrack(0);
        std::cout << std::endl;
    }
}