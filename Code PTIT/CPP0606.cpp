#include <iostream>
#include <string>

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
        : id("00001"),
          name(""),
          gender(""),
          birth(""),
          address(""),
          number(""),
          date("") {}

    friend std::istream &operator>>(std::istream &read, NhanVien &n) {
        std::getline(read, n.name);
        std::getline(read, n.gender);
        std::getline(read, n.birth);
        std::getline(read, n.address);
        std::getline(read, n.number);
        std::getline(read, n.date);
        return read;
    }

    friend std::ostream &operator>>(std::ostream &print, const NhanVien &n) {
        print << n.id << " " << n.name << " " << n.gender << " " << n.birth
              << " " << n.address << " " << n.number << " " << n.date;
        return print;
    }
};

int main() {
    NhanVien a;
    std::cin >> a;
    std::cout >> a;
    return 0;
}
