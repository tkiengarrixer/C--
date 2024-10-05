#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAXN = 200001;
int N, Q;
int A[MAXN];
int lastPos[MAXN];
int BIT_freq[MAXN], BIT_xor[MAXN];

// Cập nhật giá trị x vào vị trí idx của BIT
void update(int BIT[], int idx, int x) {
    while (idx <= N) {
        BIT[idx] ^= x;
        idx += idx & -idx;
    }
}

// Tính tổng XOR từ 1 đến idx
int query(int BIT[], int idx) {
    int res = 0;
    while (idx > 0) {
        res ^= BIT[idx];
        idx -= idx & -idx;
    }
    return res;
}

// Hàm xử lý một truy vấn XOR từ L đến R
int rangeXOR(int L, int R) {
    return query(BIT_xor, R) ^ query(BIT_xor, L - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // Map để lưu vị trí xuất hiện cuối cùng của từng phần tử
    unordered_map<int, int> lastOccurrence;
    
    for (int i = 1; i <= N; ++i) {
        // Nếu phần tử A[i] đã xuất hiện trước đó
        if (lastOccurrence[A[i]] != 0) {
            // Lấy vị trí xuất hiện cuối cùng của A[i]
            int prevPos = lastOccurrence[A[i]];
            // Xóa A[i] khỏi BIT tại vị trí prevPos
            update(BIT_xor, prevPos, A[i]);
        }
        
        // Cập nhật vị trí xuất hiện mới của A[i]
        lastOccurrence[A[i]] = i;
        // Thêm A[i] vào BIT tại vị trí hiện tại i
        update(BIT_xor, i, A[i]);
    }

    // Xử lý các truy vấn
    while (Q--) {
        int L, R;
        cin >> L >> R;
        // Kết quả truy vấn XOR trong đoạn [L, R]
        cout << rangeXOR(L, R) << "\n";
    }

    return 0;
}
