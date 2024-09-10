#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        std::set<int> temp;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            temp.insert(a[i]);
        }
        int flag = -1;
        for (int i = 0; i < n; ++i) {
            int num = a[i] + x;
            if (temp.find(num) != temp.end()) {
                flag = 1;
                break;
            }
        }
        std::cout << flag << std::endl;
    }
}
