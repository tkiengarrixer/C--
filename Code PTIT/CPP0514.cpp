#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

struct SinhVien {
    std::string id;
    std::string name;
    std::string className;
    std::string birth;
    double gpa;
};

void normalizeName(SinhVien &a) {
    std::string result;
    std::stringstream ss(a.name);
    std::string word;
    while (ss >> word) {
        word[0] = toupper(word[0]);
        for (int i = 1; i < word.size(); ++i) word[i] = tolower(word[i]);
        result = result + word + " ";
    }
    a.name = result;
}

void normalizeBirth(SinhVien &a) {
    std::stringstream ss(a.birth);
    std::string day, month, year;
    std::getline(ss, day, '/');
    std::getline(ss, month, '/');
    std::getline(ss, year);
    if (day.size() == 1) day = "0" + day;
    if (month.size() == 1) month = "0" + month;
    a.birth = day + "/" + month + "/" + year;
}

void nhap(SinhVien *ds, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin.ignore();
        std::getline(std::cin, ds[i].name);
        normalizeName(ds[i]);
        std::getline(std::cin, ds[i].className);
        std::getline(std::cin, ds[i].birth);
        normalizeBirth(ds[i]);
        std::cin >> ds[i].gpa;
    }
}

void in(SinhVien *ds, int n) {
    for (int i = 0; i < n; ++i) {
        if (i < 9) {
            ds[i].id = "B20DCCN00" + std::to_string(i + 1);
        } else
            ds[i].id = "B20DCCN0" + std::to_string(i + 1);
        std::cout << ds[i].id << " " << ds[i].name << ds[i].className << " "
                  << ds[i].birth << " " << std::fixed << std::setprecision(2)
                  << ds[i].gpa << std::endl;
    }
}

int main() {
    struct SinhVien ds[50];
    int N;
    std::cin >> N;
    nhap(ds, N);
    in(ds, N);
    return 0;
}