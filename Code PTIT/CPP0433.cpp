#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

bool compare(std::pair<int, int> &pair1, std::pair<int, int> &pair2) {
    if (pair1.second == pair2.second)
        return pair1.first < pair2.first;
    else
        return pair1.second > pair2.second;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        ;
        std::map<int, int> freq;
        while (n--) {
            int a;
            std::cin >> a;
            freq[a]++;
        }
        std::vector<std::pair<int, int>> a(freq.begin(), freq.end());
        std::sort(a.begin(), a.end(), compare);
        for (auto &pair : a) {
            for (int i = 1; i <= pair.second; ++i)
                std::cout << pair.first << " ";
        }
        std::cout << std::endl;
    }
}