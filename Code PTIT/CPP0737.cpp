#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::vector<int> result;
        double max = -1e9 * 1.0;
        for (int i = 0; i <= n - k; ++i) {
            double avg = 0;
            for (int j = i; j < i + k; ++j) {
                avg += a[j];
            }
            avg = (1.0 * avg) / k;
            if (avg > max) {
                result.clear();
                for (int j = i; j < i + k && j < n; ++j) {
                    result.push_back(a[j]);
                }
                max = avg;
            }
        }
        for (int i = 0; i < result.size(); ++i) std::cout << result[i] << " ";
        std::cout << std::endl;
    }
}