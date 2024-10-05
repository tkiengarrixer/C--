#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

long long sumDigit(long long n){
    long long total = 0;
    while(n > 0){
        total += (n % 10);
        n /= 10;
    }
    return total;
}

long long solve(long long n){
    if(n == 0) return 0;
    long long len = log10(n);
    long long res = 45 * len * pow(10, len - 1);
    for(long long i = pow(10, len); i <= n; ++i)
        res += sumDigit(i);
    return res;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        cout << solve(b) - solve(a) << endl;
    }
    return 0;
}