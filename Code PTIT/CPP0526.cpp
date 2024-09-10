#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

struct People {
    std::string name, birth;
};

void input(People *a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].name;
        std::cin.ignore();
        std::getline(std::cin, a[i].birth);
    }
}

bool compare(const People &a, const People &b) {
    std::stringstream ssa(a.birth);
    std::string day_a, month_a, year_a;
    std::getline(ssa, day_a, '/');
    std::getline(ssa, month_a, '/');
    std::getline(ssa, year_a);

    std::stringstream ssb(b.birth);
    std::string day_b, month_b, year_b;
    std::getline(ssb, day_b, '/');
    std::getline(ssb, month_b, '/');
    std::getline(ssb, year_b);

    // int a_month = stoi(month_a);
    // int a_day = stoi(day_b);
    // int a_year = stoi(year_b);

    if (year_a > year_b) return false;
    if (year_a < year_b) return true;
    if (month_a > month_b) return false;
    if (month_a < month_b) return true;
    if (day_a > day_b) return false;
    return true;
}

void sort(People *a, int n) { std::sort(a, a + n, compare); }

void print(People *a, int n) {
    std::cout << a[n - 1].name << std::endl;
    std::cout << a[0].name;
}

int main() {
    int n;
    std::cin >> n;
    People a[n];
    input(a, n);
    sort(a, n);
    print(a, n);
}