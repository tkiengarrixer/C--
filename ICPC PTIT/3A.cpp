/*
BÀI 3A - HÀNH TRÌNH THAM QUAN

Bảo tàng dân tộc học Việt Nam tại Hà Nội mới khánh thành thêm một cơ sở. Trong
bảo tàng có tất cả N+M địa điểm tham quan, tương ứng ngôi nhà của mỗi dân tộc
cùng những đặc trưng văn hóa và phong tục tập quán, trong đó có N dân tộc của
đất nước ta (khu A) và M dân tộc khác trên thế giới (khu B). Các địa điểm được
đánh số từ 1 à N và từ 1à M.

Là một vị khách du lịch mới đến Việt Nam, Mr. Tee muốn tham quan bảo tàng dân
tộc học đầu tiên. Chuyến tham quan của anh bắt đầu từ địa điểm 1 và kết thúc tại
địa điểm N của khu A, và có thể chuyển sang thăm các địa điểm của khu B một cách
xen kẽ. Để dễ dàng trong việc đánh dấu các địa điểm đã được thăm, Mr. Tee đưa ra
quy tắc thứ tự thăm bên khu A và B là phải tăng dần (+1), tức là các địa điểm
thuộc cùng một khu, địa điểm nào có số thứ tự nhỏ hơn sẽ phải được thăm trước.

Ví dụ danh sách các địa điểm được tham quan có thể như sau: 1A, 2A, 1B, 3A, 2B…
hay 1A, 1B, 2B, 3B, 2A, 4B, …

Tuy nhiên, khi di chuyển từ địa điểm X tới địa điểm Y, năng lượng tiêu hao của
Mr. Tee bằng khoảng cách XY^2. Các bạn hãy tính xem Mr. Tee sẽ tiêu hao ít nhất
bao nhiêu năng lượng để có thể tham quan hết các địa điểm tham quan của bảo
tàng?

Input:

Dòng đầu tiên chứa 3 số nguyên N, M, K (1 ≤ N, M ≤ 1000, 1 ≤ K ≤ 10).

N dòng tiếp theo, dòng thứ i gồm 2 số nguyên mô tả địa điểm thứ i của khu A.

M dòng tiếp theo, dòng thứ j gồm 2 số nguyên mô tả địa điểm thứ j của khu B.

Các tọa độ nằm trong khoảng 0 tới 1000.

Output:

In ra một số nguyên là đáp án tìm được.
*/
#include <bits/stdc++.h>

int main() {
    int n, m, k;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> a(n);
    std::vector<std::pair<int, int>> b(m);
    for (int i = 0; i < n; ++i) std::cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; ++i) std::cin >> b[i].first >> b[i].second;
}