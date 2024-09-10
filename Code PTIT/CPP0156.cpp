#include <iostream>
using namespace std;

long long count(long long b, long long p) {
    if (b == 0) return 0;
    long long count1 = (b >= 1) ? (b - 1) / p + 1 : 0;
    long long count2 = (b >= p - 1) ? (b - (p - 1)) / p + 1 : 0;
    return count1 + count2;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long b, p;
        cin >> b >> p;
        cout << count(b, p) << endl;
    }
    return 0;
}
