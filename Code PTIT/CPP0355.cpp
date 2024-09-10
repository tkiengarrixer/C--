#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::vector<std::string> temp;
    while (std::cin >> s) {
        for (int i = 0; i < s.size(); ++i) s[i] = tolower(s[i]);
        temp.push_back(s);
    }
    bool flag = true;
    for (int i = 0; i < temp.size(); ++i) {
        if (flag) {
            temp[i][0] = toupper(temp[i][0]);
            flag = false;
        }
        if (temp[i][temp[i].size() - 1] == '.' ||
            temp[i][temp[i].size() - 1] == '?' ||
            temp[i][temp[i].size() - 1] == '!') {
            temp[i].pop_back();
            std::cout << temp[i] << std::endl;
            flag = true;
        } else
            std::cout << temp[i] << " ";
    }
    return 0;
}
