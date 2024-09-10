#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

struct SinhVien {
    std::string name;
    std::string className;
    int day, month, year;
    double gpa;
};

void nhapThongTinSV(SinhVien &a) {
    std::getline(std::cin, a.name);
    std::cin >> a.className;
    std::cin >> a.day;
    std::cin.ignore(1, '/');
    std::cin >> a.month;
    std::cin.ignore(1, '/');
    std::cin >> a.year;
    std::cin >> a.gpa;
}

void inThongTinSV(SinhVien a) {
    std::cout << "N20DCCN001" << " " << a.name << " " << a.className << " ";
    if (a.day < 10)
        std::cout << "0" << a.day << "/";
    else
        std::cout << a.day << "/";
    if (a.month < 10)
        std::cout << "0" << a.month << "/";
    else
        std::cout << a.month << "/";
    std::cout << a.year << " " << std::fixed << std::setprecision(2) << a.gpa;
}

int main() {
    struct SinhVien a;
    nhapThongTinSV(a);
    inThongTinSV(a);
    return 0;
}