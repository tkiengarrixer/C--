#include <iomanip>
#include <iostream>
#include <string>

struct ThiSinh {
    std::string name;
    std::string birthday;
    double grade1, grade2, grade3;
};

void nhap(ThiSinh &student) {
    std::getline(std::cin, student.name);
    std::cin >> student.birthday;
    std::cin >> student.grade1 >> student.grade2 >> student.grade3;
}

void in(ThiSinh student) {
    std::cout << student.name << " " << student.birthday << " " << std::fixed
              << std::setprecision(1)
              << student.grade1 + student.grade2 + student.grade3;
}

int main() {
    struct ThiSinh A;
    nhap(A);
    in(A);
    return 0;
}