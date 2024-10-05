#include <cmath>
#include <iostream>

struct Point {
    long long x, y, z;
};

/*
​
     x2−x1  y2−y1  z2−z1         a1 b1 c1
 det x3−x1  y3−y1  z3−z1 hay det a2 b2 c2 = 0
     x4−x1  y4−y1  z4−y1         a3 b3 c3
​
det = a1 * b2 * c3 + a2 * b3 * c1 + b1 * c2 * a3 - a1 * b3 * c2 - a2 * b1 * c3
-a3 * b2 * c1

*/
bool coplanarCheck(Point p1, Point p2, Point p3, Point p4) {
    long long a1 = p2.x - p1.x, b1 = p2.y - p1.y, c1 = p2.z - p1.z;
    long long a2 = p3.x - p1.x, b2 = p3.y - p1.y, c2 = p3.z - p1.z;
    long long a3 = p4.x - p1.x, b3 = p4.y - p1.y, c3 = p4.z - p1.z;

    long long det = a1 * b2 * c3 + a2 * b3 * c1 + a3 * b1 * c2 - a1 * b3 * c2 -
                    a2 * b1 * c3 - a3 * b2 * c1;
    return det == 0;
}

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        Point p1, p2, p3, p4;
        std::cin >> p1.x >> p1.y >> p1.z >> p2.x >> p2.y >> p2.z >> p3.x >>
            p3.y >> p3.z >> p4.x >> p4.y >> p4.z;
        if (coplanarCheck(p1, p2, p3, p4))
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << std::endl;
    }
}