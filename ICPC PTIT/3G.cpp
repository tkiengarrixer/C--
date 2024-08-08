/*
BÀI 3G - CHẠY ĐUA

Thỏ và Rùa tham gia một cuộc thi chạy. Có N đoạn đường bằng nhau và có độ dài là
1 đơn vị, mỗi đoạn đường có nền đất khác nhau, do đó, vận tốc của Thỏ và Rùa
trên từng đoạn đường lần lượt là 1/A[i] và 1/B[i].

Thỏ khinh thường địch nên chấp Rùa thích xuất phát ở đâu cũng được (chọn vị trí
ngẫu nhiên trên tổng đoạn đường có độ dài N), còn Thỏ sẽ xuất phát ở vị trí 0
bên trái cùng. Đổi lại, Thỏ được phép sắp xếp thứ tự các đoạn đường.

Các bạn hãy tính thử xem trong trường hợp tối ưu, xác suất Thỏ thắng cuộc là bao
nhiêu? Thỏ thắng khi và chỉ khi tại một vị trí nào đó trên đường đua, Thỏ đuổi
kịp Rùa, ngược lại, Rùa sẽ là người dành chiến thắng.

Lưu ý: chỉ cần Thỏ bắt kịp được Rùa, không cần yêu cầu Thỏ phải về đích trước
Rùa.

Input:

Dòng đầu tiên là số nguyên N (1 ≤ N ≤ 105).

N dòng tiếp theo, mỗi dòng gồm hai số nguyên A[i] và B[i] (1 ≤ A[i], B[i] ≤
109).

Output:

In ra xác suất mà Thỏ giành chiến thắng lớn nhất có thể dưới dạng phân số tối
giản “P Q” biểu diễn cho P/Q (trường hợp Thỏ luôn thua, in ra 0 1).
*/

#include <bits/stdc++.h>

int GCD(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<double, double>> x(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        x[i] = {1.0 / b, 1.0 / a};
    }
    std::sort(x.begin(), x.end(), std::greater<std::pair<double, double>>());
    int winCount = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i].second >= x[i].first) ++winCount;
    }
    int total = n;
    int common = GCD(winCount, total);
    std::cout << winCount / common << " " << total / common;
}