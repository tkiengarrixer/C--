#include <iostream>
#include <vector>

using namespace std;

class DSU {
   public:
    DSU(int n) : parent(n + 1), rank(n + 1, 0), size(n + 1, 1) {
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void union_set(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                ++rank[rootX];
            }
        }
    }

    int get_size(int x) { return size[find(x)]; }

   private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;  // Track size of each component
};

void check_connected(const vector<vector<int>> &adj,
                     const vector<bool> &present) {
    int n = present.size() - 1;
    DSU dsu(n);

    for (int v = 1; v <= n; ++v) {
        if (present[v]) {
            for (int u : adj[v]) {
                if (present[u]) {
                    dsu.union_set(v, u);
                }
            }
        }
    }

    int root = -1;
    for (int i = 1; i <= n; ++i) {
        if (present[i]) {
            root = dsu.find(i);
            break;
        }
    }

    if (root == -1) {
        cout << "NO" << endl;
        return;
    }

    bool all_connected = true;
    int total_present = 0;
    for (int i = 1; i <= n; ++i) {
        if (present[i]) {
            total_present++;
            if (dsu.find(i) != root) {
                all_connected = false;
                break;
            }
        }
    }

    cout << (all_connected ? "YES" : "NO") << endl;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    vector<bool> present(N + 1, false);
    for (int i = 0; i < N; ++i) {
        present[P[i]] = true;
    }
    check_connected(adj, present);

    for (int i = 0; i < N - 1; ++i) {
        present[P[i]] = false;
        check_connected(adj, present);
    }

    return 0;
}
