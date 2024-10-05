#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    int n, k, b;
    std::cin >> n >> k >> b;
    std::vector<int> broken(100001, 0);
    while (b--) {
        int p;
        std::cin >> p;
        broken[p] = 1;
    }

    int count = 0;

    // Tìm số đèn cần sửa trong cửa sổ độ lớn k, bắt đầu vị trí 1
    for (int i = 1; i <= k; ++i)
        if (broken[i] == 1) ++count;

    int result = count;

    // Trượt cửa sổ đến cuối mảng và tìm số đèn tối thiểu cần sửa
    for (int i = k + 1; i <= n; ++i) {
        // Thêm vào cửa sổ
        if (broken[i] == 1) ++count;
        // Loại bỏ khỏi cửa sổ trong khi trượt
        if (broken[i - k] == 1) --count;
        result = std::min(result, count);
    }

    std::cout << result << std::endl;
}