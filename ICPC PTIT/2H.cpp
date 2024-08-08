#include <bits/stdc++.h>

bool check(int set1, int set2) { return (set1 & set2) == 0; }

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::unordered_map<int, std::vector<int>> sum_to_sets;

    int total_sets = 1 << n;

    for (int mask = 1; mask < total_sets; ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += a[i];
            }
        }
        sum_to_sets[sum].push_back(mask);
    }

    std::vector<int> result;
    for (const auto& pair : sum_to_sets) {
        const std::vector<int>& sets = pair.second;
        bool found = false;
        for (size_t i = 0; i < sets.size() && !found; ++i) {
            for (size_t j = i + 1; j < sets.size(); ++j) {
                if (check(sets[i], sets[j])) {
                    result.push_back(pair.first);
                    found = true;
                    break;
                }
            }
        }
    }

    std::sort(result.begin(), result.end());

    std::cout << result.size() << std::endl;
    for (int x : result) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
