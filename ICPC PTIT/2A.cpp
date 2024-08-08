#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 50;

struct Rectangle {
    int xA, yA, xB, yB;
};

int parent[MAX_N];
int rank[MAX_N];

// Khởi tạo Union-Find
void init(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 1;
    }
}

// Tìm gốc của tập hợp chứa phần tử u
int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

// Hợp nhất hai tập hợp
void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;

    if (rank[u] < rank[v]) {
        swap(u, v);
    }
    parent[v] = u;
    if (rank[u] == rank[v]) {
        rank[u]++;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<Rectangle> rectangles(N);
        for (int i = 0; i < N; ++i) {
            cin >> rectangles[i].xA >> rectangles[i].yA >> rectangles[i].xB >>
                rectangles[i].yB;
        }

        // Khởi tạo Union-Find
        init(N);

        // Kiểm tra tất cả các cặp hình chữ nhật
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (rectangles[i].xB < rectangles[j].xA ||
                    rectangles[j].xB < rectangles[i].xA ||
                    rectangles[i].yB < rectangles[j].yA ||
                    rectangles[j].yB < rectangles[i].yA) {
                    // Không giao nhau, hợp nhất tập hợp
                    unite(i, j);
                }
            }
        }

        // Đếm số lượng tập hợp (vùng riêng biệt)
        int distinctRegions = 0;
        for (int i = 0; i < N; ++i) {
            if (parent[i] == i) {
                distinctRegions++;
            }
        }

        cout << distinctRegions << endl;
    }

    return 0;
}
