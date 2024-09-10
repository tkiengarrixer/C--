#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> multiply(std::string a, std::string b) {
    int n = a.size();
    int m = b.size();
    std::vector<int> result(n + m + 1, 0);
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[i + j] += (a[i] - '0') * (b[j] - '0');
            result[i + j + 1] += (result[i + j] / 10);
            result[i + j] %= 10;
        }
    }
    for (int i = 0; i < result.size() - 1; ++i) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }

    while (result.size() >= 2 && result.back() == 0) result.pop_back();
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string a, b;
        std::cin >> a >> b;
        std::vector<int> result = multiply(a, b);
        for (int i = 0; i < result.size(); ++i) std::cout << result[i];
        std::cout << std::endl;
    }
}