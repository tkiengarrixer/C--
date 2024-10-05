#include <algorithm>
#include <iostream>
#include <string>

// Hàm để thực hiện phép trừ hai số nguyên lớn
std::string subtract(const std::string &num1, const std::string &num2) {
    // Đảm bảo num1 lớn hơn num2
    bool isNegative = false;
    std::string larger = num1, smaller = num2;

    if (num1 < num2) {
        isNegative = true;
        larger = num2;
        smaller = num1;
    }

    std::string result;
    int carry = 0;

    // Đảo ngược hai chuỗi để bắt đầu trừ từ chữ số thấp nhất
    std::reverse(larger.begin(), larger.end());
    std::reverse(smaller.begin(), smaller.end());

    // Thực hiện phép trừ
    for (size_t i = 0; i < larger.size(); ++i) {
        int digit1 = larger[i] - '0';  // Chuyển đổi ký tự thành số nguyên
        int digit2 = (i < smaller.size())
                         ? (smaller[i] - '0')
                         : 0;  // Nếu smaller đã hết số thì dùng 0

        if (digit1 < digit2 + carry) {
            digit1 += 10;  // Mượn 1
            carry = 1;
        } else {
            carry = 0;
        }

        int subResult = digit1 - digit2 - carry;
        result.push_back(subResult + '0');  // Chuyển đổi lại thành ký tự
    }

    // Xóa các chữ số không cần thiết ở đầu chuỗi
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    // Đảo ngược kết quả và thêm dấu '-' nếu là số âm
    std::reverse(result.begin(), result.end());
    if (isNegative) {
        result.insert(result.begin(), '-');
    }

    return result;
}

std::string add(const std::string &num1, const std::string &num2) {
    std::string n1 = num1;
    std::string n2 = num2;

    std::reverse(n1.begin(), n1.end());
    std::reverse(n2.begin(), n2.end());

    std::string result;
    int carry = 0;
    size_t len1 = n1.size(), len2 = n2.size();
    size_t maxLength = std::max(len1, len2);

    for (size_t i = 0; i < maxLength; ++i) {
        int digit1 = (i < len1) ? (n1[i] - '0') : 0;
        int digit2 = (i < len2) ? (n2[i] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry > 0) result.push_back(carry + '0');

    std::reverse(result.begin(), result.end());
    return result;
}

bool check(const std::string &s) {
    int count = s.size();
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') --count;
    }
    return count == 0;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string x, y;
        std::cin >> x >> y;
        std::string count = "0";  // Khởi tạo count là 0
        std::string one = "1";

        while (true) {
            if (check(x)) break;
            x = subtract(x, y);  // Lưu kết quả của phép trừ vào x
            count = add(count, one);  // Cộng 1 vào count
            std::cout << x << std::endl;
        }

        std::cout << count << std::endl;
    }

    return 0;
}
