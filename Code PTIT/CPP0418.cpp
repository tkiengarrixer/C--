#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::set<int> set1;
        std::set<int> set2;
        while (n--) {
            int a;
            std::cin >> a;
            set1.insert(a);
        }
        while (m--) {
            int a;
            std::cin >> a;
            set2.insert(a);
        }
        std::vector<int> intersectionArray;
        std::set_intersection(set1.begin(), set1.end(), set2.begin(),
                              set2.end(),
                              std::back_inserter(intersectionArray));
        std::vector<int> unionArray;
        std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
                       std::back_inserter(unionArray));
        for (int i = 0; i < unionArray.size(); ++i)
            std::cout << unionArray[i] << " ";
        std::cout << std::endl;
        for (int i = 0; i < intersectionArray.size(); ++i)
            std::cout << intersectionArray[i] << " ";
        std::cout << std::endl;
    }
}