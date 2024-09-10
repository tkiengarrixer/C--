#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

struct NhanVien {
    std::string name;
    std::string gender;
    std::string date;
    std::string address;
    std::string num;
    std::string contractDate;
};

void nhap(NhanVien &a) {
    std::getline(std::cin, a.name);
    std::cin >> a.gender;
    std::cin >> a.date;
    std::cin.ignore();
    std::getline(std::cin, a.address);
    std::cin >> a.num;
    std::cin >> a.contractDate;
}

void in(NhanVien a) {
    std::cout << "00001" << " " << a.name << " " << a.gender << " " << a.date
              << " " << a.address << " " << a.num << " " << a.contractDate;
}

int main() {
    struct NhanVien a;
    nhap(a);
    in(a);
    return 0;
}