#include <iostream>
using namespace std;

#define max 100

// تابع چاپ شکل ۱
void printShape1(int size) {
    int a, b;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a = i;
            b = size - i - 1;
            if (a <= b) {
                if (j >= a && j <= b)
                    cout << "*";
                else
                    cout << " ";
            } else {
                if (j >= b && j <= a)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
}


// تابع چاپ شکل ۲
void printShape2(int n) {

    // Pattern Size
    int size = 2 * n - 1;
    int front = 0;
    int back = size - 1;
    int a[max][max];
    while (n != 0) {
        for (int i = front; i <= back; i++) {
            for (int j = front; j <= back; j++) {
                if (i == front || i == back ||
                    j == front || j == back)
                    a[i][j] = n;
            }
        }
        ++front;
        --back;
        --n;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

// تابع چاپ شکل ۳
void printShape3(int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j)
            cout << " ";
        for (int j = 0; j <= i-1; ++j)
            cout << "*";
        cout << endl;
    }
}

int main() {
    int choice, size;

    // دریافت انتخاب کاربر
    cout << "Choose a shape:" << endl;
    cout << "1. Shape 1" << endl;
    cout << "2. Shape 2" << endl;
    cout << "3. Shape 3" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    // دریافت اندازه شکل از کاربر
    cout << "Enter the size of the shape: ";
    cin >> size;

    // چاپ شکل متناظر با انتخاب کاربر
    switch (choice) {
        case 1:
            printShape1(size);
            break;
        case 2:
            printShape2(size);
            break;
        case 3:
            printShape3(size);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}
