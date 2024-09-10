#include <cmath>
#include <iomanip>
#include <iostream>

struct Point {
    double x, y;
};

void input(Point &p) { std::cin >> p.x >> p.y; }

double distance(Point a, Point b) {
    double result = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    return result;
}

int main() {
    struct Point A, B;
    int t;
    std::cin >> t;
    while (t--) {
        input(A);
        input(B);
        std::cout << std::fixed << std::setprecision(4) << distance(A, B)
                  << std::endl;
    }
    return 0;
}