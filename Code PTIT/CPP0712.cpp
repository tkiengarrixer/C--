#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int n, k;
std::vector<int> current;

void print() {
    for (int i = 0; i < k; ++i) std::cout << current[i];
    std::cout << " ";
}

void backtrack(int start) {
    if (current.size() == k) {
        print();
        return;
    }
    for (int i = start; i <= n; ++i) {
        current.push_back(i);
        backtrack(i + 1);
        current.pop_back();
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> k;
        backtrack(1);
        std::cout << std::endl;
    }
}