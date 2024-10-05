#include <algorithm>
#include <iostream>
#include <vector>

int process(int x, const std::vector<int> &y, const std::vector<int> &freq) {
    int result = 0;
    // 0^x < x^0 với x != 0
    if (x == 0) return 0;

    //1^0 > 0^1
    if (x == 1) return freq[0];

    // Tìm số phần tử y > x, vì x^y > y^x (y > x, với x không thoả mãn 2 điều kiện trên)
    auto it = std::upper_bound(y.begin(), y.end(), x);
    result = y.end() - it;

    // Thêm trường hợp y = 0 và y = 1;
    result += (freq[0] + freq[1]);

    // Loại bỏ trường hợp 2^3 < 3^2 và 2^4 = 4^2, hay y = 3, y = 4 khi x = 2
    if (x == 2) result -= (freq[3] + freq[4]);
    if (x == 3) result += freq[2];

    return result;

}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, count = 0;
        std::cin >> n >> m;
        std::vector<int> x(n);
        std::vector<int> y(m);

        for (int i = 0; i < n; ++i) std::cin >> x[i];
        for (int i = 0; i < m; ++i) std::cin >> y[i];

        std::vector<int> freq(5, 0);
        for (int i = 0; i < m; ++i) {
            if (y[i] < 5) ++freq[y[i]];
        }
        std::sort(y.begin(), y.end());

        for (int i = 0; i < n; ++i) {
            count += process(x[i], y, freq);
        }

        std::cout << count << std::endl;
    }
}