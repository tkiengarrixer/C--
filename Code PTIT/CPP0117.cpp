#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        std::vector<int> a;
        while (n != 0) {
            a.push_back(n % 10);
            n /= 10;
        }
        int result = 0;
        while (true) {
            for (int i = 0; i < a.size(); ++i) result += a[i];
            a.clear();
            if (result < 10) break;
            while (result != 0) {
                a.push_back(result % 10);
                result /= 10;
            }
        }
        std::cout << result << std::endl;
    }
}