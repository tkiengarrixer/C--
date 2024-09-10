#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int x;
    std::unordered_map<int, int> cache;
    std::vector<int> order;
    while (std::cin >> x) {
        if (cache.find(x) == cache.end()) order.push_back(x);
        cache[x]++;
    }
    for (int i = 0; i < order.size(); ++i) {
        std::cout << order[i] << " " << cache[order[i]] << std::endl;
    }
}