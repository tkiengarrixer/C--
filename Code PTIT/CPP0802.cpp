#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file("DATA.in");
    std::string num;
    long long sum = 0;
    while (file >> num) {
        int n = num.size();
        if (n > 10 || (n == 10 && num > "4294967295")) continue;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (!isdigit(num[i])) {
                flag = false;
                break;
            }
        }
        if (flag) sum += std::stoll(num);
    }
    std::cout << sum;
}
