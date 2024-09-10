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

bool compare(Student a, Student b) { return a.id < b.id; }

void sort(std::vector<Student> &list) {
    std::sort(list.begin(), list.end(), compare);
}

int main() {
    std::vector<Student> a;
    Student temp;
    while (std::cin >> temp) {
        a.push_back(temp);
    }
    sort(a);
    for (int i = 0; i < a.size(); ++i) std::cout << a[i];
}