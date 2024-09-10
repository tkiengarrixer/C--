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

    friend std::istream &operator>>(std::istream &read, SinhVien &student) {
        std::getline(read, student.name);
        std::getline(read, student.className);
        std::getline(read, student.birth);
        read >> student.gpa;
        std::stringstream ss(student.birth);
        std::string day, month, year;
        std::getline(ss, day, '/');
        std::getline(ss, month, '/');
        std::getline(ss, year);
        if (day.size() == 1) day = "0" + day;
        if (month.size() == 1) month = "0" + month;
        student.birth = day + "/" + month + "/" + year;
        return read;
    }

    friend std::ostream &operator<<(std::ostream &print, SinhVien &student) {
        print << student.id << " " << student.name << " " << student.className
              << " " << student.birth << " " << std::fixed
              << std::setprecision(2) << student.gpa;
        return print;
    }
};

int main() {
    SinhVien a;
    std::cin >> a;
    std::cout << a;
    return 0;
}