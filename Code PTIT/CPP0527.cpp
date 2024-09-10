#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Time {
    int hour, minute, second;
    int totalTime;
};

void input(Time &a) {
    std::cin >> a.hour >> a.minute >> a.second;
    a.totalTime = a.hour * 3600 + a.minute * 60 + a.second;
}

bool compare(Time a, Time b) { return a.totalTime < b.totalTime; }

void sort(std::vector<Time> &a, int n) {
    std::sort(a.begin(), a.end(), compare);
}

void print(std::vector<Time> &a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i].hour << " " << a[i].minute << " " << a[i].second
                  << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Time> a(n);
    for (int i = 0; i < n; ++i) input(a[i]);
    sort(a, n);
    print(a, n);
}