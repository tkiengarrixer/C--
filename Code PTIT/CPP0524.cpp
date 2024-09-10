#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct SinhVien {
    std::string id;
    std::string name;
    std::string className;
    double grade1, grade2, grade3;
};

void nhap(SinhVien &a) {
    std::cin.ignore();
    std::getline(std::cin, a.id);
    std::getline(std::cin, a.name);
    std::getline(std::cin, a.className);
    std::cin >> a.grade1 >> a.grade2 >> a.grade3;
}

bool compare(SinhVien a, SinhVien b) { return a.id < b.id; }
void sap_xep(SinhVien *ds, int n) { std::sort(ds, ds + n, compare); }

void in_ds(SinhVien *ds, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << i + 1 << " " << ds[i].id << " " << ds[i].name << " "
                  << ds[i].className << " " << std::fixed
                  << std::setprecision(1) << ds[i].grade1 << " " << ds[i].grade2
                  << " " << ds[i].grade3 << std::endl;
    }
}
int main() {
    int n;
    std::cin >> n;
    struct SinhVien *ds = new SinhVien[n];
    for (int i = 0; i < n; i++) {
        nhap(ds[i]);
    }
    sap_xep(ds, n);
    in_ds(ds, n);
    return 0;
}