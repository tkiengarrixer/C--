#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

void input(std::vector<long long> &a, int n) {
    for (int i = 0; i < n; ++i) std::cin >> a[i];
}

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n1, n2, n3;
        std::cin >> n1 >> n2 >> n3;
        std::vector<long long> a(n1), b(n2), c(n3);
        input(a, n1);
        input(b, n2);
        input(c, n3);
        std::vector<long long> result;
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2 && k < n3) {
            if (a[i] == b[j] && b[j] == c[k]) {
                result.push_back(a[i]);
                ++i;
                ++j;
                ++k;
            } else if (a[i] < b[j])
                ++i;
            else if (b[j] < c[k])
                ++j;
            else
                ++k;
        }
        if (!result.size())
            std::cout << "-1";
        else
            for (int i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
        std::cout << std::endl;
    }
}