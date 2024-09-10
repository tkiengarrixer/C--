#include <cmath>
#include <iomanip>
#include <iostream>

#define PI 3.141592653589793238

struct point {
    double x, y;
};

void input(point &a) { std::cin >> a.x >> a.y; }

double distance(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool isTriangle(point a, point b, point c) {
    double AB = distance(a, b);
    double BC = distance(b, c);
    double AC = distance(a, c);
    return AB + AC > BC && BC + AC > AB && AB + BC > AC;
}

double area(point a, point b, point c) {
    double AB = distance(a, b);
    double BC = distance(b, c);
    double AC = distance(a, c);
    double ABC = (AB + BC + AC) / 2.0;
    return sqrt(ABC * (ABC - AB) * (ABC - BC) * (ABC - AC));
}

double radius(point a, point b, point c) {
    double AB = distance(a, b);
    double BC = distance(b, c);
    double AC = distance(a, c);
    double s = area(a, b, c);
    return AB * AC * BC / (4.0 * s);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        point a, b, c;
        input(a);
        input(b);
        input(c);
        if (!isTriangle(a, b, c))
            std::cout << "INVALID";
        else {
            double r = radius(a, b, c);
            double area = PI * r * r;
            std::cout << std::fixed << ::std::setprecision(3) << area;
        }
        std::cout << std::endl;
    }
}