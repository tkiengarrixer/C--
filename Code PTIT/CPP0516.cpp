#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

struct Item {
    int id;
    std::string name;
    std::string type;
    double buy;
    double sell;
    double profit;
};

void scan(Item *a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin.ignore();
        a[i].id = i + 1;
        std::getline(std::cin, a[i].name);
        std::getline(std::cin, a[i].type);
        std::cin >> a[i].buy;
        std::cin >> a[i].sell;
        a[i].profit = a[i].sell - a[i].buy;
    }
}

bool compare(Item a, Item b) { return a.profit > b.profit; }

void sort(Item *a, int n) { std::stable_sort(a, a + n, compare); }

void print(Item *a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i].id << " " << a[i].name << " " << a[i].type << " "
                  << std::fixed << std::setprecision(2) << a[i].profit
                  << std::endl;
    }
}
int main() {
    int n;
    std::cin >> n;
    Item items[n];
    scan(items, n);
    sort(items, n);
    print(items, n);
}