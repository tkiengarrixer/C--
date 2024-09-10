#include <stdio.h>

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    double result = 0;
    for (int i = 1; i <= n; ++i) result += (double)1 / i;
    printf("%.4lf", result);
    return 0;
}