#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();

    std::map<std::string, int> count;

    while (t--) {
        std::string s;
        std::getline(std::cin, s);

        for (int i = 0; i < s.size(); ++i) s[i] = tolower(s[i]);

        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> container;
        while (ss >> word) {
            container.push_back(word);
        }

        std::string email;
        int len = container.size();
        email += container[len - 1];
        for (int i = 0; i < len - 1; ++i) {
            email.push_back(container[i][0]);
        }

        if (count[email] == 0) {
            count[email] = 1;
        } else {
            count[email]++;
            email += std::to_string(count[email]);
        }

        email += "@ptit.edu.vn";
        std::cout << email << std::endl;
    }

    return 0;
}