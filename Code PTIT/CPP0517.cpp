#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

struct NhanVien {
    std::string name;
    std::string gender;
    std::string birth;
    std::string address;
    std::string num;
    std::string contractbirth;
};

void nhap(NhanVien &a) {
    std::cin.ignore();
    std::getline(std::cin, a.name);
    std::cin >> a.gender;
    std::cin.ignore();
    std::cin >> a.birth;
    std::cin.ignore();
    std::getline(std::cin, a.address);
    std::cin >> a.num;
    std::cin.ignore();
    std::cin >> a.contractbirth;
}

void inds(NhanVien a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i < 9)
            std::cout << "0000" << i + 1;
        else
            std::cout << "000" << i + 1;
        std::cout << " " << a[i].name << " " << a[i].gender << " " << a[i].birth
                  << " " << a[i].address << " " << a[i].num << " "
                  << a[i].contractbirth;
        std::cout << std::endl;
    }
}

int main() {
    struct NhanVien ds[50];
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) nhap(ds[i]);
    inds(ds, N);
    return 0;
}