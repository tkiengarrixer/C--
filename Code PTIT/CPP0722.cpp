#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> factors(10003);

std::string multiply(const std::string& a, const std::string& b) {
    int n = a.size();
    int m = b.size();
    std::vector<int> c(n + m, 0);

    std::string aReversed = a;
    std::string bReversed = b;
    std::reverse(aReversed.begin(), aReversed.end());
    std::reverse(bReversed.begin(), bReversed.end());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int product = (aReversed[i] - '0') * (bReversed[j] - '0');
            c[i + j] += product;
            c[i + j + 1] += c[i + j] / 10;
            c[i + j] %= 10;
        }
    }

    std::string result;
    bool zero = true;
    for (int i = c.size() - 1; i >= 0; --i) {
        if (c[i] != 0 || !zero) {
            zero = false;
            result.push_back(c[i] + '0');
        }
    }

    return result.empty() ? "0" : result;
}

void multiplyFactors(int n) {
    int lim = sqrt(n);
    for (int i = 2; i <= lim; ++i) {
        while (n % i == 0) {
            ++factors[i];
            n /= i;
        }
    }
    if (n > 1) ++factors[n];
}

void divideFactors(int n) {
    int lim = sqrt(n);
    for (int i = 2; i <= lim; ++i) {
        while (n % i == 0) {
            --factors[i];
            n /= i;
        }
    }
    if (n > 1) --factors[n];
}

int main() {
    int n;
    std::cin >> n;
    int m = n + 1;
    for (int i = 0; i < n; ++i) multiplyFactors(2 * m - i);
    for (int i = 1; i <= m; ++i) divideFactors(i);

    std::string result = "1";
    for (int i = 0; i < factors.size(); ++i) {
        if (factors[i] > 0) {
            std::string factorStr = std::to_string(i);
            for (int j = 0; j < factors[i]; ++j) {
                result = multiply(result, factorStr);
            }
        }
    }

    std::cout << result;
    return 0;
}
