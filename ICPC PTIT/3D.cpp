/*
BÀI 3D - CHIA HẾT

Cho dãy số A[] có N phần tử.

Hãy đếm số cặp chỉ số (L, R) thỏa mãn tổng dãy con liên tiếp (A[L] + A[L+1] + …
+ A[R]) chia hết cho số nguyên M.

Input:

Dòng đầu tiên gồm 2 số nguyên dương N và M (1 ≤ N ≤ 105, 1 ≤ M, A[i] ≤ 109).

Dòng tiếp theo gồm N số nguyên mô tả dãy số A[].

Output:

In ra số cặp chỉ số thỏa mãn yêu cầu của đề bài.
*/

#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = (prefixSum[i - 1] + a[i - 1]) % m;
    }

    std::unordered_map<int, long long> freq;
    long long res = 0;

    for (int i = 0; i <= n; ++i) {
        res += freq[prefixSum[i]];
        freq[prefixSum[i]]++;
    }
    std::cout << res;
    return 0;
}
