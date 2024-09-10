#include <iostream>
#include <map>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::map<int, int> freq;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            ++freq[a[i]];
        }
        int count = 0;
        for (const auto& pair : freq) {
            if (pair.second > 1) {
                count += pair.second;
            }
        }
        std::cout << count << std::endl;
    }

    return 0;
}
