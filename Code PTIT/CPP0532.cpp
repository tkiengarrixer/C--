#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

struct Point {
    long long x, y;
};

double area(std::vector<Point> &a, long long n) {
    double result = 0;
    for (long long i = 0; i < n; ++i) {
        long long j = (i + 1) % n;
        result += ((1.0 * a[i].x * a[j].y - 1.0 * a[j].x * a[i].y));
    }
    return std::abs(result) * (1.0 / 2);
}

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        std::vector<Point> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i].x >> a[i].y;
        std::cout << std::fixed << std::setprecision(3) << area(a, n)
                  << std::endl;
    }
    return 0;
}