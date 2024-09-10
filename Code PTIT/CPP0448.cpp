#include <iostream>
#include <map>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        std::map<int, int> freq;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            freq[a[i]]++;
        }
        if (freq.find(x) != freq.end()) {
            std::cout << freq[x] << std::endl;
        } else {
            std::cout << "-1" << std::endl;
        }
    }
    return 0;
}
