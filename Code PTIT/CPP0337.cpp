#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>

int minSubStr(std::string s) {
    std::unordered_map<char, int> freq;
    // Đếm số lượng ký tự trong xâu cha
    for (int i = 0; i < s.size(); ++i) ++freq[s[i]];
    int count = freq.size();

    int minLen = s.size();
    int left = 0;
    int countUnique = 0;
    std::unordered_map<char, int> window;

    // Sliding window
    for (int right = 0; right < s.size(); ++right) {
        // Mở rộng cửa sổ sang bên phải
        ++window[s[right]];
        if (window[s[right]] == 1) ++countUnique;

        // Thu nhỏ cửa sổ từ bên trái để tìm độ dài xâu con nhỏ hơn
        while (countUnique == count) {
            minLen = std::min(minLen, right - left + 1);
            --window[s[left]];
            if (window[s[left]] == 0) --countUnique;
            ++left;
        }
    }
    return minLen;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        std::cout << minSubStr(s) << std::endl;
    }
    return 0;
}
