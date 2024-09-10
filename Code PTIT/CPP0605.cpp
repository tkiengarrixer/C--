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

class PhanSo {
   private:
    long long a, b;

   public:
    PhanSo(long long t = 1, long long m = 1) : a(t), b(m) {}

    void rutgon() {
        long long gcd = GCD(a, b);
        a /= gcd;
        b /= gcd;
    }

    friend std::istream &operator>>(std::istream &read, PhanSo &p) {
        read >> p.a >> p.b;
        return read;
    }

    friend std::ostream &operator<<(std::ostream &print, PhanSo &p) {
        print << p.a << "/" << p.b;
        return print;
    }
};

int main() {
    PhanSo p(1, 1);
    std::cin >> p;
    p.rutgon();
    std::cout << p;
    return 0;
}