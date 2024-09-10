#include <iomanip>
#include <iostream>
#include <string>

int countID = 1;
class SinhVien {
   private:
    std::string id;
    std::string name;
    std::string className;
    std::string birth;
    double gpa;

   public:
    SinhVien() {
        id = "";
        name = "";
        className = "";
        birth = "";
        gpa = 0;
    }

    friend std::istream &operator>>(std::istream &input, SinhVien &student) {
        std::cin.ignore();
        std::getline(input, student.name);
        std::getline(input, student.className);
        std::getline(input, student.birth);
        input >> student.gpa;
        if (countID < 10)
            student.id = "B20DCCN00" + std::to_string(countID);
        else
            student.id = "B20DCCN0" + std::to_string(countID);
        ++countID;
        std::stringstream ss(student.birth);
        std::string day, month, year;
        std::getline(ss, day, '/');
        std::getline(ss, month, '/');
        std::getline(ss, year);
        if (day.size() == 1) day = "0" + day;
        if (month.size() == 1) month = "0" + month;
        student.birth = day + "/" + month + "/" + year;
        return input;
    }

    friend std::ostream &operator<<(std::ostream &print, SinhVien &student) {
        print << student.id << " " << student.name << " " << student.className
              << " " << student.birth << " " << std::fixed
              << std::setprecision(2) << student.gpa << std::endl;
        return print;
    }
};

int main() {
    SinhVien ds[50];
    int N, i;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> ds[i];
    }
    for (i = 0; i < N; i++) {
        std::cout << ds[i];
    }
    return 0;
}