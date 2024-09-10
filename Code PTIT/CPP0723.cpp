#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

std::string fact(char c) {
    if (c == '0' || c == '1')
        return "1";
    else if (c == '2')
        return "2";
    else if (c == '3')
        return "3";
    else if (c == '4')
        return "322";
    else if (c == '5')
        return "5";
    else if (c == '6')
        return "53";
    else if (c == '7')
        return "7";
    else if (c == '8')
        return "7222";
    else
        return "7332";
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string a;
        std::cin >> n >> a;
        std::string result = "";
        for (char c : a) {
            result += fact(c);
        }
        std::sort(result.begin(), result.end(), std::greater<char>());
        while (result[result.size() - 1] == '1') result.erase(result.end() - 1);
        std::cout << result;
        std::cout << std::endl;
    }
    return 0;
}
