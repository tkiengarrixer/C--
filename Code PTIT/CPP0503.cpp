#include <cmath>
#include <iostream>

long long GCD(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

struct PhanSo {
    long long a, b;
};

void nhap(PhanSo &p) { std::cin >> p.a >> p.b; }

void rutgon(PhanSo &p) {
    long long gcd = GCD(p.a, p.b);
    p.a /= gcd;
    p.b /= gcd;
}

void in(PhanSo p) { std::cout << p.a << "/" << p.b; }

int main() {
    struct PhanSo p;
    nhap(p);
    rutgon(p);
    in(p);
    return 0;
}