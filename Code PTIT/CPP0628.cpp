#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Enterprise {
   private:
   public:
    std::string id;
    std::string name;
    int num;

    Enterprise() {
        id = "";
        name = "";
        num = 0;
    }

    friend std::istream &operator>>(std::istream &input, Enterprise &a) {
        std::getline(input, a.id);
        std::getline(input, a.name);
        input >> a.num;
        std::cin.ignore();
        return input;
    }

    friend std::ostream &operator<<(std::ostream &print, Enterprise &a) {
        print << a.id << " " << a.name << " " << a.num << std::endl;
        return print;
    }
};

bool compare(Enterprise a, Enterprise b) {
    if (a.num == b.num) return a.id < b.id;
    return a.num > b.num;
}
void sort(std::vector<Enterprise> &a) {
    std::sort(a.begin(), a.end(), compare);
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::vector<Enterprise> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    sort(a);
    for (int i = 0; i < n; ++i) std::cout << a[i];
}