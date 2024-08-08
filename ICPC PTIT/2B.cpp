/*
BÀI 2B - BIỂU DIỄN THẬP PHÂN CÓ KHÔNG QUÁ 2 CHỮ SỐ

Cho một số nguyên dương N, hãy đếm xem có bao nhiêu số nguyên dương trong
đoạn[1, N] có biểu diễn thập phân gồm không quá 2 chữ số.
Input: Một số nguyên dương N duy nhất (1 ≤ N ≤ 10^9).
Output: In ra một số nguyên duy nhất là đáp án của bài toán.
*/

#include <cmath>
#include <iostream>
#include <set>

using namespace std;

long long N, n, ok;
long long a[20];
set<long long> res;

void initilize() {
    for (long long i = 1; i <= n; ++i) a[i] = 0;
}

void create() {
    long long i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}

void solve(long long n) {
    initilize();
    ok = 1;
    while (ok) {
        for (long long d1 = 0; d1 < 10; d1++)
            for (long long d2 = d1 + 1; d2 < 10; d2++) {
                long long sum = 0;
                for (long long i = 1; i <= n; ++i)
                    if (a[i] == 0)
                        sum = sum * 10 + d1;
                    else
                        sum = sum * 10 + d2;
                if (sum <= N) res.insert(sum);
            }
        create();
    }
}

int main() {
    cin >> N;
    n = log10(N) + 1;
    for (long long i = 1; i <= n; ++i) solve(i);
    cout << res.size() - 1 << endl;
    return 0;
}