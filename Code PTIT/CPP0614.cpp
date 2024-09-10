#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int countId = 1;

class NhanVien {
   private:
    std::string id;
    std::string name;
    std::string gender;
    std::string birth;
    std::string address;
    std::string number;
    std::string date;

   public:
    NhanVien()
        : id(""),
          name(""),
          gender(""),
          birth(""),
          address(""),
          number(""),
          date("") {}

    friend std::istream &operator>>(std::istream &read, NhanVien &n) {
        scanf("\n");
        if (countId < 10)
            n.id = "0000" + std::to_string(countId);
        else
            n.id = "000" + std::to_string(countId);
        ++countId;
        std::getline(read, n.name);
        std::getline(read, n.gender);
        std::getline(read, n.birth);
        std::getline(read, n.address);
        std::getline(read, n.number);
        std::getline(read, n.date);
        return read;
    }

    friend std::ostream &operator<<(std::ostream &print, const NhanVien &n) {
        print << n.id << " " << n.name << " " << n.gender << " " << n.birth
              << " " << n.address << " " << n.number << " " << n.date
              << std::endl;
        return print;
    }
};

int main() {
    NhanVien ds[50];
    int N, i;
    std::cin >> N;
    for (i = 0; i < N; i++) std::cin >> ds[i];
    for (i = 0; i < N; i++) std::cout << ds[i];
    return 0;
}
