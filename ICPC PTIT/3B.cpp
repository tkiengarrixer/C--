/*
BÀI 3B - THỪA SỐ NGUYÊN TỐ

Mọi số tự nhiên lớn hơn 1 có thể viết một cách duy nhất (không kể sự sai khác về
thứ tự các thừa số) thành tích các thừa số nguyên tố. Trong bài toán này, chúng
ta sẽ quan tâm đến các cách biểu diễn (có tính đến thứ tự) của một số thành tích
các thừa số nguyên tố. Ví dụ:

10 = 2 × 5 = 5 × 2

20 = 2 × 2 × 5 = 2 × 5 × 2 = 5 × 2 × 2

Gọi F(k) là số cách biểu diễn k thành tích các thừa số nguyên tố có tính đến thứ
tự các thừa số. Như vậy, F(10) = 2 và F(20) = 3.

Cho số nguyên dương n, tìm số k nhỏ nhất mà F(k) = n.

Input

Dòng đầu tiên là số lượng bộ test t (t ≤ 1000)
Mỗi test gồm một số nguyên n (n ≤ 2^63)
Output

Với mỗi bộ dữ liệu, ghi ra một dòng gồm 2 số n, k mà F(k) = n.
*/

#include <bits/stdc++.h>

unsigned long long countPartition(int n) {
    std::vector<unsigned long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            dp[j] += dp[j - i];
        }
    }
    return dp[n];
}

unsigned long long fact(unsigned long long n) {
    unsigned long long result = 1;
    for (unsigned long long i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

unsigned long long countWay(unsigned long long k) {
    std::vector<int> factors;
    for (int i = 2; i <= sqrt(k); ++i) {
        while (k % i == 0) {
            factors.push_back(i);
            k /= i;
        }
    }
    if (k > 1) {
        factors.push_back(k);
    }

    std::map<int, int> freq;
    for (int factor : factors) {
        freq[factor]++;
    }

    unsigned long long result = fact(factors.size());
    for (const auto& entry : freq) {
        result /= fact(entry.second);
    }

    return result;
}

unsigned long long findMin(unsigned long long n) {
    unsigned long long k = 1;
    while (true) {
        if (countWay(k) == n) {
            return k;
        }
        k++;
        if (k > 1e6) break;
    }
    return -1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        unsigned long long n;
        std::cin >> n;
        if (n == 1)
            std::cout << "1" << " " << "2" << "\n";
        else {
            unsigned long long k = findMin(n);
            std::cout << n << " " << k << "\n";
        }
    }

    return 0;
}
