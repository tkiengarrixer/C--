#include <iostream>
#include <vector>

int arr[5] = {1, 2, 3, 4, 5};

void change(int arr[], int index, int value) { arr[index] = value; }

int a = 1;
int b = 1;

int main() {
    change(arr, 5, 2);
    std::cout << &arr[5] << std::endl;
    std::cout << &a << " " << &b << " ";
    std::cout << "a + b = " << a + b;
    return 0;
}
