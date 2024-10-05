#include <algorithm>
#include <cmath>
#include <fstream>
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

int main() {
    long long M;
    cin >> M;
    M *= 2;
    long long cnt = 0;
    for(long long i = 1; i <= sqrt(M); ++i){
        if(M % i == 0){
            long long x = i, y = M / i;
            if(((x + y) % 2 == 1) && ((y - x) % 2 == 1)) cnt+=2;
        }
    }
    cout << cnt;
    return 0;
}