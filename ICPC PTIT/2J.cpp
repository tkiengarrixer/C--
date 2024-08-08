#include <math.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int check(map<int, int> mp, int n) {
    int val = mp[1];
    for (int i = 2; i <= n; i++) {
        if (mp[i] != val) return 1;
    }
    return 0;
}

int main() {
    int m, n;
    cin >> m >> n;
    map<int, int> mp;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        mp[k]++;
    }

    if (!check(mp, n)) {
        cout << "NONE";
        return 0;
    }

    int Max = 0;
    for (int i = 1; i <= n; i++) {
        Max = max(mp[i], Max);
    }

    int Max2 = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[i] != Max) Max2 = max(mp[i], Max2);
    }

    if (Max2 == 0) {
        cout << "NONE";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (mp[i] == Max2) {
            cout << i;
            break;
        }
    }
    return 0;
}