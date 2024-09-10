#include <iostream>
#include <set>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::set<int> num;
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            num.insert(a);
        }
        if (num.size() <= 1)
            std::cout << "-1";
        else {
            auto it = num.begin();
            int min = *it;
            auto secondMin = *++it;
            std::cout << min << " " << secondMin;
        }
        std::cout << std::endl;
    }
}