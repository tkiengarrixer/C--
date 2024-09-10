#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int countId = 1;

class Teacher {
   private:
    std::string subject;

   public:
    std::string id;
    std::string name;

    Teacher() {
        id = "";
        name = "";
        subject = "";
    }

    friend std::istream &operator>>(std::istream &input, Teacher &a) {
        std::getline(input, a.name);

        std::string s;
        std::getline(input, s);
        std::stringstream ss(s);
        std::string word;
        while (ss >> word) {
            word[0] = toupper(word[0]);
            a.subject += word[0];
        }

        if (countId < 10)
            a.id = "GV0" + std::to_string(countId);
        else
            a.id = "GV" + std::to_string(countId);
        ++countId;
        return input;
    }

    friend std::ostream &operator<<(std::ostream &print, Teacher &a) {
        print << a.id << " " << a.name << " " << a.subject << std::endl;
        return print;
    }
};

bool compare(Teacher a, Teacher b) {
    std::stringstream ssa(a.name);
    std::string a_name;
    while (ssa >> a_name) {
    }

    std::stringstream ssb(b.name);
    std::string b_name;
    while (ssb >> b_name) {
    }
    if (a_name == b_name) return a.id < b.id;
    return a_name < b_name;
}

void sort(std::vector<Teacher> &a) { std::sort(a.begin(), a.end(), compare); }

int main() {
    int n;
    std::cin >> n;
    std::vector<Teacher> a(n);
    std::cin.ignore();
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    sort(a);
    for (int i = 0; i < n; ++i) std::cout << a[i];
}