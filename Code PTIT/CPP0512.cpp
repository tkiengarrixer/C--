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
    long long tu, mau;
};

void rutGon(PhanSo &a) {
    long long gcd = GCD(a.tu, a.mau);
    a.tu /= gcd;
    a.mau /= gcd;
}

PhanSo sum(PhanSo a, PhanSo b) {
    PhanSo result;
    result.tu = a.tu * b.mau + b.tu * a.mau;
    result.mau = a.mau * b.mau;
    result.tu *= result.tu;
    result.mau *= result.mau;
    rutGon(result);
    return result;
}

PhanSo multi(PhanSo a, PhanSo b, PhanSo c) {
    PhanSo result;
    result.tu = a.tu * b.tu * c.tu;
    result.mau = a.mau * b.mau * c.mau;
    rutGon(result);
    return result;
}

void process(PhanSo a, PhanSo b) {
    PhanSo c = sum(a, b);
    PhanSo d = multi(a, b, c);
    std::cout << c.tu << "/" << c.mau << " " << d.tu << "/" << d.mau
              << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        PhanSo A;
        PhanSo B;
        std::cin >> A.tu >> A.mau >> B.tu >> B.mau;
        process(A, B);
    }
}