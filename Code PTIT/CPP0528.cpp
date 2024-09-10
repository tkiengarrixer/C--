#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Student {
    int number;
    std::string id;
    std::string name;
    std::string className;
    std::string email;
    std::string company;
};

void print(std::vector<Student> &a, int n) {
    std::cin.ignore();
    for (int i = 0; i < n; ++i) {
        a[i].number = i + 1;
        std::getline(std::cin, a[i].id);
        std::getline(std::cin, a[i].name);
        std::getline(std::cin, a[i].className);
        std::getline(std::cin, a[i].email);
        std::getline(std::cin, a[i].company);
    }
}

bool compare(Student a, Student b) { return a.name < b.name; }

void sort(std::vector<Student> &a) { std::sort(a.begin(), a.end(), compare); }

int main() {
    int n;
    std::cin >> n;
    std::vector<Student> a(n);
    print(a, n);
    sort(a);
    int q;
    std::cin >> q;
    while (q--) {
        std::string company;
        std::cin >> company;
        for (int i = 0; i < n; ++i) {
            if (company == a[i].company) {
                std::cout << a[i].number << " " << a[i].id << " " << a[i].name
                          << " " << a[i].className << " " << a[i].email << " "
                          << a[i].company << std::endl;
            }
        }
    }
}
