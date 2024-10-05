#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

bool compare(std::string a, std::string b) {
    if (a.size() > b.size()) return true;
    return false;
}

int main() {
    int n;
    std::cin >> n;
    int count = 0;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    std::sort(a.begin(), a.end(), compare);

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j]) count += 2;
            else if (a[i].find(a[j]) != std::string::npos) ++count;
        }
    }

    std::cout << count;
}