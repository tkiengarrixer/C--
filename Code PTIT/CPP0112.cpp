#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        double x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        double distance =
            std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

        std::cout << std::fixed << std::setprecision(4) << distance
                  << std::endl;
    }
    return 0;
}
