#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int countID = 1;

class SinhVien {
   private:
    std::string id;
    std::string name;
    std::string className;
    std::string birth;

   public:
    double gpa;
    SinhVien() {
        id = "";
        name = "";
        className = "";
        birth = "";
        gpa = 0;
    }

    friend std::istream &operator>>(std::istream &input, SinhVien &student) {
        scanf("\n");
        std::getline(input, student.name);
        std::getline(input, student.className);
        std::getline(input, student.birth);
        input >> student.gpa;

        if (countID < 10)
            student.id = "B20DCCN00" + std::to_string(countID);
        else
            student.id = "B20DCCN0" + std::to_string(countID);
        ++countID;

        std::stringstream ss(student.name);
        std::string word, name;
        while (ss >> word) {
            word[0] = toupper(word[0]);
            for (int i = 1; i < word.size(); ++i) word[i] = tolower(word[i]);
            name = name + word + " ";
        }

        std::stringstream ssb(student.birth);
        std::string day, month, year;
        std::getline(ssb, day, '/');
        std::getline(ssb, month, '/');
        std::getline(ssb, year);
        if (day.size() == 1) day = "0" + day;
        if (month.size() == 1) month = "0" + month;
        student.birth = day + "/" + month + "/" + year;
        student.name = name;
        return input;
    }

    friend std::ostream &operator<<(std::ostream &print,
                                    const SinhVien &student) {
        print << student.id << " " << student.name << student.className << " "
              << student.birth << " " << std::fixed << std::setprecision(2)
              << student.gpa << std::endl;
        return print;
    }
};

bool compare(SinhVien a, SinhVien b) { return a.gpa > b.gpa; }

void sapxep(SinhVien *ds, int N) { std::sort(ds, ds + N, compare); }

int main() {
    SinhVien ds[50];
    int N, i;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> ds[i];
    }
    sapxep(ds, N);
    for (i = 0; i < N; i++) {
        std::cout << ds[i];
    }
    return 0;
}
