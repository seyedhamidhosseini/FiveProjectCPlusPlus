#include <iostream>
#include <string>
using namespace std;

int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;

    while (true) {
        ++year;

        // Check if all digits are distinct
        string yearStr = to_string(year);
        bool isDistinct = true;
        for (int i = 0; i < yearStr.size(); ++i) {
            for (int j = i + 1; j < yearStr.size(); ++j) {
                if (yearStr[i] == yearStr[j]) {
                    isDistinct = false;
                    break;
                }
            }
            if (!isDistinct) {
                break;
            }
        }

        if (isDistinct) {
            cout << "Next happy year after " << year - 1 << " is: " << year << endl;
            break;
        }
    }

    return 0;
}
