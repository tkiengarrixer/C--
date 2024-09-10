#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int countId = 1;

using namespace std;

struct NhanVien {
    std::string id;
    std::string name;
    std::string gender;
    std::string birth;
    std::string address;
    std::string num;
    std::string contractDate;
};

void normalizeBirth(NhanVien &a) {
    std::stringstream ss(a.birth);
    std::string day, month, year;

    std::getline(ss, day, '/');
    std::getline(ss, month, '/');
    std::getline(ss, year);

    if (day.size() == 1) day = "0" + day;
    if (month.size() == 1) month = "0" + month;
    // if (month > "12") swap(month, day);
    a.birth = day + "/" + month + "/" + year;
}

void normalizeDate(NhanVien &a) {
    std::stringstream ss(a.contractDate);
    std::string day, month, year;

    std::getline(ss, day, '/');
    std::getline(ss, month, '/');
    std::getline(ss, year);

    if (day.size() == 1) day = "0" + day;
    if (month.size() == 1) month = "0" + month;
    // if (month > "12") swap(month, day);
    a.contractDate = day + "/" + month + "/" + year;
}

void nhap(NhanVien &a) {
    if (countId < 10)
        a.id = "0000" + std::to_string(countId);
    else
        a.id = "000" + std::to_string(countId);
    ++countId;
    std::cin.ignore();
    std::getline(std::cin, a.name);
    std::cin >> a.gender;
    std::cin.ignore();

    std::cin >> a.birth;
    normalizeBirth(a);
    std::cin.ignore();

    std::getline(std::cin, a.address);
    std::cin >> a.num;
    std::cin.ignore();

    std::cin >> a.contractDate;
    normalizeDate(a);
}

bool compare(const NhanVien &a, const NhanVien &b) {
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

void sapxep(NhanVien *a, int n) { std::sort(a, a + n, compare); }

void inds(NhanVien a[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i].id << " " << a[i].name << " " << a[i].gender << " "
                  << a[i].birth << " " << a[i].address << " " << a[i].num << " "
                  << a[i].contractDate;
        std::cout << std::endl;
    }
}

int main() {
    struct NhanVien ds[50];
    int N, i;
    std::cin >> N;
    for (i = 0; i < N; i++) nhap(ds[i]);
    sapxep(ds, N);
    inds(ds, N);
    return 0;
}