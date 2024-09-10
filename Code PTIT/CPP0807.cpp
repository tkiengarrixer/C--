#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

int main() {
    std::fstream input("DATA.in");
    int n, m;
    input >> n >> m;
    int num;
    std::set<int> set1;
    std::set<int> set2;

    while (n--) {
        input >> num;
        set1.insert(num);
    }
    while (m--) {
        input >> num;
        set2.insert(num);
    }

    std::vector<int> intersecSet;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                          std::back_inserter(intersecSet));
    for (int i = 0; i < intersecSet.size(); ++i)
        std::cout << intersecSet[i] << " ";
}