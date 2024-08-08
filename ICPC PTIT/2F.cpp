/*
BÀI 2F - DÃY SỐ CÓ CÁC PHẦN TỬ BẰNG NHAU

Cho dãy số A[] có N phần tử là một hoán vị của 1, 2, 3, …, N. Bạn được phép thực
hiện phép biến đổi sau: mỗi bước, chọn một đoạn K phần tử liên tiếp, sau đó gán
giá trị của cả đoạn này bằng giá trị phần tử nhỏ nhất trong đoạn.

Các bạn hãy tính xem cần sử dụng ít nhất bao nhiêu phép biến đổi để có thể thu
được một dãy số mới có tất cả các phần tử đều bằng nhau?

Input:

Dòng đầu tiên là số nguyên dương N và K (2 ≤ K ≤ N ≤ 100000).

Dòng tiếp theo là N số nguyên mô tả dãy số hoán vị A[].

Output:

In ra một số nguyên là số bước đổi ít nhất cần thực hiện.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n + 3];
    int l = m - 1;

    int index;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) index = i;
    }

    int LenR, LenL;

    LenR = (n - index) + 1;
    LenL = (index - 1) + 1;
    cout << ceil(1.0 * (LenL + l - 1) / l) + ceil(1.0 * (LenR + l - 1) / l) - 2;
}