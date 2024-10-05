#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Hàm cộng hai số nguyên lớn dưới dạng chuỗi
std::string add_large_numbers(const std::string &num1,
                              const std::string &num2) {
    std::string result;
    int carry = 0;
    int n1 = num1.size();
    int n2 = num2.size();
    int max_len = std::max(n1, n2);

    for (int i = 0; i < max_len; ++i) {
        int digit1 = i < n1 ? num1[n1 - 1 - i] - '0' : 0;
        int digit2 = i < n2 ? num2[n2 - 1 - i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    if (carry) result.push_back(carry + '0');
    std::reverse(result.begin(), result.end());
    return result;
}

// Hàm trừ hai số nguyên lớn dưới dạng chuỗi
std::string subtract_large_numbers(const std::string &num1,
                                   const std::string &num2) {
    std::string result;
    int borrow = 0;
    int n1 = num1.size();
    int n2 = num2.size();

    for (int i = 0; i < n1; ++i) {
        int digit1 = num1[n1 - 1 - i] - '0';
        int digit2 = (i < n2) ? num2[n2 - 1 - i] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }
    // Remove leading zeros
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

// Hàm nhân hai số nguyên lớn dưới dạng chuỗi
std::string multiply_large_numbers(const std::string &num1,
                                   const std::string &num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    std::string result(n1 + n2, '0');

    for (int i = n1 - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = n2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0') +
                      (result[i + j + 1] - '0') + carry;
            carry = mul / 10;
            result[i + j + 1] = (mul % 10) + '0';
        }
        result[i] += carry;
    }
    // Remove leading zeros
    size_t start = result.find_first_not_of('0');
    if (start != std::string::npos) {
        result = result.substr(start);
    } else {
        result = "0";
    }
    return result;
}

// Hàm chia hai số nguyên lớn và lấy k chữ số sau dấu thập phân
std::string divide_large_numbers(const std::string &num1,
                                 const std::string &num2, int k) {
    std::string result;
    std::string quotient;
    std::string remainder = num1;
    std::string divisor = num2;

    if (divisor == "0") {
        return "ERROR: Division by zero";  // Xử lý chia cho 0
    }

    // Phần nguyên
    std::string integer_part;
    while (remainder.size() > divisor.size() ||
           (remainder.size() == divisor.size() && remainder >= divisor)) {
        int count = 0;
        std::string temp = divisor;
        while (temp.size() < remainder.size()) {
            temp += '0';
        }
        while (temp <= remainder) {
            remainder = subtract_large_numbers(remainder, temp);
            count++;
            temp = add_large_numbers(temp, divisor);
        }
        integer_part += std::to_string(count);
    }

    // Phần thập phân
    std::string fractional_part;
    for (int i = 0; i < k; ++i) {
        remainder += '0';
        int count = 0;
        std::string temp = divisor;
        while (temp.size() < remainder.size()) {
            temp += '0';
        }
        while (temp <= remainder) {
            remainder = subtract_large_numbers(remainder, temp);
            count++;
            temp = add_large_numbers(temp, divisor);
        }
        fractional_part += std::to_string(count);
    }

    // Kết hợp phần nguyên và phần thập phân
    result = integer_part + "." + fractional_part;
    return result;
}

string myPow(string a, int n){
    if(n == 0) return "1";
    if(n == 1) return a;
    string tmp = myPow(a, n/ 2);
    if(n % 2 == 0) return multiply_large_numbers(tmp, tmp);
    return multiply_large_numbers(multiply_large_numbers(tmp, tmp), a);
}


int main() {
    int a, b;
    cin >> a >> b;
    string res = add_large_numbers(myPow("2", a), myPow("3", b));
    cout << res[0];
    return 0;
}