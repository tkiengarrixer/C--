#include <cmath>
#include <iostream>

/*
Giải thích:
- Ta có tổng s của tập A = [1,..., n]
- Giả sử tập A được chia thành 2 tập con A1 và A2 sao cho s1 = sum(A1) và s2 =
sum(A2)
- Ta có s1 + s2 = s (1)
- Ta cũng có |s1 - s2| = m (2)
- Từ (1) và (2) ta có hệ phương trình:
    s1 + s2 = s
    s1 - s2 = m

    => s1 = (s + m) / 2
    => s2 = s - s1 hay s2 = (s - m) / 2
- Để thoả mãn thì s và m phải cùng chẵn hoặc cùng lẻ và gcd(s1, s2) = 1
*/

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

bool isTrue(long long s1, long long s2, long long s, long long m) {
    if (!(((m % 2 == 0 && s % 2 == 0) || (m % 2 != 0 && s % 2 != 0)) &&
          gcd(s1, s2) == 1))
        return false;

    return true;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n, m;
        std::cin >> n >> m;
        long long s = n * (n + 1) / 2;
        long long s1 = (s + m) / 2;
        long long s2 = s - s1;

        if (isTrue(s1, s2, s, m))
            std::cout << "Yes";
        else
            std::cout << "No";
        std::cout << std::endl;
    }
}