#include <algorithm>
#include <deque>
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
        std::deque<int> dq;
        std::vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && a[i] >= a[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) result.push_back(a[dq.front()]);
        }
        for (int i = 0; i < result.size(); ++i) std::cout << result[i] << " ";
        std::cout << std::endl;
    }
}