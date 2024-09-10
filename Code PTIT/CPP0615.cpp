#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int countId = 1;

class NhanVien {
   private:
    std::string id;
    std::string name;
    std::string gender;
    std::string address;
    std::string number;
    std::string date;

   public:
    std::string birth;
    std::string day, month, year;
    NhanVien()
        : id(""),
          name(""),
          gender(""),
          birth(""),
          address(""),
          number(""),
          date("") {}

    friend std::istream &operator>>(std::istream &read, NhanVien &n) {
        if (countId < 10)
            n.id = "0000" + std::to_string(countId);
        else
            n.id = "000" + std::to_string(countId);
        ++countId;
        read.ignore();
        std::getline(read, n.name);
        std::getline(read, n.gender);
        std::getline(read, n.birth);

        std::stringstream ss(n.birth);
        std::getline(ss, n.day, '/');
        std::getline(ss, n.month, '/');
        std::getline(ss, n.year);

        std::getline(read, n.address);
        std::getline(read, n.number);
        std::getline(read, n.date);
        return read;
    }

    friend std::ostream &operator<<(std::ostream &print, NhanVien &n) {
        print << n.id << " " << n.name << " " << n.gender << " " << n.birth
              << " " << n.address << " " << n.number << " " << n.date
              << std::endl;
        return print;
    }
};

bool compare(NhanVien &a, NhanVien &b) {
    if (a.year < b.year) return true;
    if (a.year > b.year) return false;
    if (a.month < b.month) return true;
    if (a.month > b.month) return false;
    if (a.day < b.day) return true;
    return false;
}

void sapxep(NhanVien *ds, int N) { std::sort(ds, ds + N, compare); }

int main() {
    NhanVien ds[50];
    int N, i;
    std::cin >> N;
    for (i = 0; i < N; i++) std::cin >> ds[i];
    sapxep(ds, N);
    for (i = 0; i < N; i++) std::cout << ds[i];
    return 0;
}
