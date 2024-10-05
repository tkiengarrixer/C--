#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// Hàm so sánh hai chuỗi số lớn
bool isSmaller(string str1, string str2) {
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2) return true;
    if (n1 > n2) return false;

    for (int i = 0; i < n1; i++) {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    return false;
}

// Hàm trừ chuỗi số lớn
string subtractStrings(string num1, string num2) {
    string result = "";

    int n1 = num1.length(), n2 = num2.length();
    int diff = n1 - n2;

    int carry = 0;

    for (int i = n2 - 1; i >= 0; i--) {
        int sub = ((num1[i + diff] - '0') - (num2[i] - '0') - carry);

        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result.push_back(sub + '0');
    }

    for (int i = n1 - n2 - 1; i >= 0; i--) {
        if (num1[i] == '0' && carry) {
            result.push_back('9');
            continue;
        }
        int sub = ((num1[i] - '0') - carry);
        if (i > 0 || sub > 0) result.push_back(sub + '0');
        carry = 0;
    }

    reverse(result.begin(), result.end());

    // Loại bỏ các số 0 thừa ở đầu
    size_t pos = result.find_first_not_of('0');
    if (pos != string::npos) {
        return result.substr(pos);
    }

    return "0";
}

// Hàm chia chuỗi số lớn
pair<string, string> divideStrings(string dividend, string divisor) {
    if (isSmaller(dividend, divisor)) {
        return {"0", dividend};  // Trả về thương là 0, phần dư là dividend
    }

    string quotient = "";
    string current = "0";

    for (char digit : dividend) {
        current += digit;

        // Loại bỏ các số 0 ở đầu
        size_t pos = current.find_first_not_of('0');
        if (pos != string::npos) {
            current = current.substr(pos);
        } else {
            current = "0";
        }

        int count = 0;
        while (!isSmaller(current, divisor)) {
            current = subtractStrings(current, divisor);
            count++;
        }

        quotient += (count + '0');
    }

    // Loại bỏ các số 0 thừa ở đầu của thương
    size_t pos = quotient.find_first_not_of('0');
    if (pos != string::npos) {
        quotient = quotient.substr(pos);
    } else {
        quotient = "0";
    }

    return {quotient, current};  // Trả về cả thương và phần dư
}

int main() {
    string num1 = "1111111111111111111111111111111111111111111";
    string num2 = "7";

    pair<string, string> result = divideStrings(num1, num2);

    cout << "Kết quả phép chia: " << result.first << endl;
    cout << "Phần dư: " << result.second << endl;

    return 0;
}