#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::vector<int> temp(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            temp[i] = a[i];
        }

        std::sort(temp.begin(), temp.end());
        std::vector<std::string> result;

        for (int i = 0; i < n; ++i) {
            auto it = std::upper_bound(temp.begin(), temp.end(), a[i]);
            if (it != temp.end())
                result.push_back(std::to_string(*it));
            else
                result.push_back("_");
        }

        for (int i = 0; i < result.size(); ++i) std::cout << result[i] << " ";
        std::cout << std::endl;
    }
}
