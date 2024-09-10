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

PhanSo tong(PhanSo p, PhanSo q) {
    PhanSo result;
    result.a = p.a * q.b + q.a * p.b;
    result.b = p.b * q.b;
    rutgon(result);
    return result;
}

void in(PhanSo p) { std::cout << p.a << "/" << p.b; }

int main() {
    PhanSo p, q;
    nhap(p);
    nhap(q);
    PhanSo t = tong(p, q);
    in(t);
    return 0;
}