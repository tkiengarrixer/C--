#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Student {
   private:
    std::string name;
    std::string email;

   public:
    std::string id;
    std::string className;

    Student() {
        id = "";
        name = "";
        className = "";
        email = "";
    }

    friend std::istream &operator>>(std::istream &input, Student &a) {
        std::getline(input, a.id);
        std::getline(input, a.name);
        std::getline(input, a.className);
        std::getline(input, a.email);
        return input;
    }

    friend std::ostream &operator<<(std::ostream &print, Student &a) {
        print << a.id << " " << a.name << " " << a.className << " " << a.email
              << std::endl;
        return print;
    }
};

bool compare(Student a, Student b) {
    if (a.className == b.className)
        return a.id < b.id;
    else
        return a.className < b.className;
}

void sort(std::vector<Student> &list) {
    std::sort(list.begin(), list.end(), compare);
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::vector<Student> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int q;
    std::cin >> q;
    while (q--) {
        std::string year;
        std::cin >> year;
        std::string sortYear = year.substr(2, 2);
        bool printed = false;
        for (int i = 0; i < n; ++i) {
            if (a[i].className.find(sortYear) != std::string::npos) {
                if (!printed) {
                    std::cout << "DANH SACH SINH VIEN KHOA" << " " << year
                              << ":" << std::endl;
                    printed = true;
                }
                std::cout << a[i];
            }
        }
    }
}