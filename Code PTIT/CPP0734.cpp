#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

long long maxArea(std::vector<long long> height, long long m) {
    long long max = 0;

    std::stack<long long> stack;
    for (int i = 0; i < m; ++i) {
        while (!stack.empty() && height[stack.top()] > height[i]) {
            long long h = height[stack.top()];
            stack.pop();
            long long w;
            if (stack.empty())
                w = i;
            else
                w = i - stack.top() - 1;
            max = std::max(max, h * w);
        }
        stack.push(i);
    }

    while (!stack.empty()) {
        long long h = height[stack.top()];
        stack.pop();
        long long w;
        if (stack.empty())
            w = m;
        else
            w = m - stack.top() - 1;
        max = std::max(max, h * w);
    }

    return max;
}

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n, m;
        std::cin >> n >> m;
        long long result = 0;

        std::vector<std::vector<long long>> a(n, std::vector<long long>(m));
        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < m; ++j) std::cin >> a[i][j];
        }

        std::vector<std::vector<long long>> temp(n, std::vector<long long>(m, 0));

        for (long long i = 0; i < m; ++i) temp[0][i] = a[0][i];
        for (long long i = 1; i < n; ++i) {
            for (long long j = 0; j < m; ++j) {
                if (a[i][j]) temp[i][j] = temp[i - 1][j] + 1;
            }

            result = std::max(result, maxArea(temp[i], m));
        }

        std::cout << result << std::endl;
    }
    return 0;
}