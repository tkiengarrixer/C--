#include <cmath>
#include <iostream>
#include <vector>

int n;
std::vector<int> col;
std::vector<int> d1;  // Mang danh dau duong cheo chinh da dung
std::vector<int> d2;  // Mảng danh dau duong cheo phu da dung
int result = 0;

void backTrack(int row) {
    if (row == n) {
        ++result;  // Truong hop co so
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (col[i] || d1[row - i + n - 1] || d2[row + i])
            continue;  // Kiem tra quan hau o (row, i) co bi an hay khong

        col[i] = d1[row - i + n - 1] = d2[row + i] =
            1;               // Neu khong bi an, danh dau o duoc su dung
        backTrack(row + 1);  // Backtrack hang tiep theo
        col[i] = d1[row - i + n - 1] = d2[row + i] =
            0;  // Tra lai trang thai de duyet cac truong hop khac
    }
}
int main() {
    std::cin >> n;
    col.resize(n, 0);
    d1.resize(2 * n - 1, 0);
    d2.resize(2 * n - 1, 0);
    backTrack(0);
    std::cout << result;
}