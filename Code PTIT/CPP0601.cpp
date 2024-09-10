#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class SinhVien {
   private:
    std::string id;
    std::string name;
    std::string className;
    std::string birth;
    double gpa;

   public:
    SinhVien() {
        id = "B20DCCN001";
        name = "";
        className = "";
        birth = "";
        gpa = 0.0;
    }

    void nhap() {
        std::getline(std::cin, name);
        std::getline(std::cin, className);
        std::getline(std::cin, birth);
        std::cin >> gpa;
        normalize();
    }

    void normalize() {
        std::stringstream ss(birth);
        std::string day, month, year;
        std::getline(ss, day, '/');
        std::getline(ss, month, '/');
        std::getline(ss, year);
        if (day.size() == 1) day = "0" + day;
        if (month.size() == 1) month = "0" + month;
        birth = day + "/" + month + "/" + year;
    }

    void xuat() {
        std::cout << id << " " << name << " " << className << " " << birth
                  << " " << std::fixed << std::setprecision(2) << gpa;
    }
};

int main() {
    SinhVien a;
    a.nhap();
    a.xuat();
    return 0;
}