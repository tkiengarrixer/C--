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
    void simply() {
        long long gcd = GCD(a, b);
        a /= gcd;
        b /= gcd;
    }
    PhanSo() : a(0), b(1) {}

    PhanSo(long long a, long long b) : a(a), b(b) { simply(); }

    friend std::istream &operator>>(std::istream &read, PhanSo &p) {
        read >> p.a >> p.b;
        p.simply();
        return read;
    }

    friend std::ostream &operator<<(std::ostream &print, const PhanSo &p) {
        print << p.a << "/" << p.b;
        return print;
    }

    friend PhanSo operator+(const PhanSo &p, const PhanSo &q) {
        long long a = p.a * q.b + q.a * p.b;
        long long b = p.b * q.b;
        PhanSo result(a, b);
        result.simply();
        return result;
    }
};

int main() {
    PhanSo p(1, 1), q(1, 1);
    std::cin >> p >> q;
    std::cout << p + q;
    return 0;
}