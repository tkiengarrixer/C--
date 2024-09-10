#include <iostream>
#include <string>

std::string min(int m, int n) {
    std::string res(m, '0');
    for (int i = m - 1; i >= 0; i--) {
        if (n > 9) {
            res[i] = '9';
            n -= 9;
        } else {
            if (i == 0) {
                res[i] = n + '0';
            } else {
                res[0] = '1';
                res[i] = n - 1 + '0';
            }
            break;
        }
    }
    return res;
}

std::string max(int m, int n) {
    std::string res(m, '0');
    for (int i = 0; i < m; i++) {
        if (n > 9) {
            res[i] = '9';
            n -= 9;
        } else {
            res[i] = n + '0';
            break;
        }
    }
    return res;
}

int main() {
    int m, n;
    std::cin >> m >> n;
    if (m * 9 < n || (n == 0 && m > 1)) {
        std::cout << -1 << " " << -1;
    } else {
        std::cout << min(m, n) << " " << max(m, n);
    }
    return 0;
}
