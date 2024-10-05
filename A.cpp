#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <list>
#include <iomanip>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    long long n; cin >> n;
    string s;
    cin >> s;
    
    long long cntR = 0, cntG = 0, cntB = 0;
    for (long long i = 0; i < n; i ++){
        if(s[i] == 'R') cntR ++;
        else if(s[i] == 'G') cntG ++;
        else cntB ++;
    }

    long long res1 = cntR * cntG * cntB;

    for (long long i = 0; i < n; i ++){
        for (long long k = i + 2; k < n; k ++){
            if((i + k) % 2 == 1) continue;
            else{
                long long mid = (i +k) / 2;

                if(s[i] != s[mid] && s[mid] != s[k] && s[i] != s[k]) res1 --;
            }
        }
    }
    cout << res1;

    return 0;
}