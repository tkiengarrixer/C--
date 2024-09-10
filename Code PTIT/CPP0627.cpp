#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int countId = 1;

class Teacher {
   public:
    std::string subject;
    std::string shortSub;
    std::string id;
    std::string name;
    std::string lowerName;

    Teacher() {
        id = "";
        name = "";
        subject = "";
    }

    friend std::istream &operator>>(std::istream &input, Teacher &a) {
        std::getline(input, a.name);
        a.lowerName = a.name;
        for (int i = 0; i < a.lowerName.size(); ++i)
            a.lowerName[i] = tolower(a.lowerName[i]);
        std::getline(input, a.subject);
        std::stringstream ss(a.subject);
        std::string word;
        while (ss >> word) {
            word[0] = toupper(word[0]);
            a.shortSub += word[0];
        }

        if (countId < 10)
            a.id = "GV0" + std::to_string(countId);
        else
            a.id = "GV" + std::to_string(countId);
        ++countId;
        return input;
    }

    friend std::ostream &operator<<(std::ostream &print, Teacher &a) {
        print << a.id << " " << a.name << " " << a.shortSub << std::endl;
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

    int q;
    std::cin >> q;
    std::cin.ignore();
    while (q--) {
        std::string name;
        std::getline(std::cin, name);
        std::string lowerName = name;
        for (int i = 0; i < lowerName.size(); ++i)
            lowerName[i] = tolower(lowerName[i]);
        bool printed = false;
        for (int i = 0; i < n; ++i) {
            if (a[i].lowerName.find(lowerName) != std::string::npos) {
                if (!printed) {
                    std::cout << "DANH SACH GIANG VIEN THEO TU KHOA " << name
                              << ":" << std::endl;
                    printed = true;
                }
                std::cout << a[i];
            }
        }
    }
}