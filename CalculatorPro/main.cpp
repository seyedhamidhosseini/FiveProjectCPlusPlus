#include <iostream>

using namespace std;

double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    if (y == 0) {
        cout << "Error: Division by zero." << endl;
        return 0;
    }
    return x / y;
}

double power(double base, double exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i)
        result *= base;
    return result;
}

double factorial(int n) {
    double result = 1.0;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

double sine(double angle) {
    double result = angle;
    double term = angle;
    int n = 1;
    while (true) {
        term *= -angle * angle / ((2 * n) * (2 * n + 1));
        if (term == 0)
            break;
        result += term;
        n++;
    }
    return result;
}

double cosine(double angle) {
    double result = 1.0;
    double term = 1.0;
    int n = 1;
    while (true) {
        term *= -angle * angle / ((2 * n - 1) * (2 * n));
        if (term == 0)
            break;
        result += term;
        n++;
    }
    return result;
}

double tangent(double angle) {
    return sine(angle) / cosine(angle);
}

double arcsine(double value) {
    double result = value;
    double term = value;
    int n = 1;
    while (true) {
        term *= (2 * n - 1) * (2 * n - 1) * value * value / ((2 * n) * (2 * n + 1));
        if (term == 0)
            break;
        result += term;
        n++;
    }
    return result;
}

double arccosine(double value) {
    const double PI = 3.14159265358979323846;
    return PI / 2.0 - arcsine(value);
}

double arctangent(double value) {
    double result = value;
    double term = value;
    int n = 1;
    while (true) {
        term *= -value * value * (2 * n - 1) / (2 * n + 1);
        if (term == 0)
            break;
        result += term;
        n++;
    }
    return result;
}

double custom_log(double x) {
    if (x <= 0) {
        cout << "Error: Argument must be positive." << endl;
        return -999999; // مقدار ویژه برای نشان دادن خطا
    }

    double sum = 0.0;
    double term = (x - 1) / (x + 1);
    double power = term;
    int n = 1;

    while (true) {
        sum += power / n;
        power *= term * term;
        n += 2;
        if (power < 1e-6)
            break;
    }

    return 2 * sum;
}

double logarithm(double base, double x) {
    if (base <= 0 || x <= 0) {
        cout << "Error: Base and argument must be positive." << endl;
        return -999999; // مقدار ویژه برای نشان دادن خطا
    }

    return custom_log(x) / custom_log(base);
}

double square_root(double x) {
    if (x < 0) {
        cout << "Error: Argument must be non-negative." << endl;
        return -999999; // مقدار ویژه برای نشان دادن خطا
    }

    double guess = x / 2.0;
    double prev_guess = 0.0;
    const double EPSILON = 1e-6;

    while (abs(guess - prev_guess) > EPSILON) {
        prev_guess = guess;
        guess = (guess + x / guess) / 2.0;
    }

    return guess;
}

double cube_root(double x) {
    double guess = x / 3.0;
    double prev_guess = 0.0;
    const double EPSILON = 1e-6;

    while (abs(guess - prev_guess) > EPSILON) {
        prev_guess = guess;
        guess = (2.0 * guess + x / (guess * guess)) / 3.0;
    }

    return guess;
}

int main() {
    int choice;
    double x, y, result;
    bool exit = false;

    while (!exit) {
        cout << "Choose an operation:" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Power" << endl;
        cout << "6. Factorial" << endl;
        cout << "7. Sine" << endl;
        cout << "8. Cosine" << endl;
        cout << "9. Tangent" << endl;
        cout << "10. Arcsine" << endl;
        cout << "11. Arccosine" << endl;
        cout << "12. Arctangent" << endl;
        cout << "13. Logarithm" << endl;
        cout << "14. Square Root" << endl;
        cout << "15. Cube Root" << endl;
        cout << "16. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            cout << "Enter two numbers: ";
            cin >> x >> y;
        } else if (choice == 6) {
            cout << "Enter the number: ";
            int n;
            cin >> n;
            result = factorial(n);
            cout << "Result: " << result << endl;
            continue;
        } else if (choice >= 7 && choice <= 12) {
            cout << "Enter the angle in radians: ";
            cin >> x;
        } else if (choice == 13) {
            cout << "Enter the base and argument: ";
            cin >> x >> y;
            result = logarithm(x, y);
            cout << "Result: " << result << endl;
            continue;
        } else if (choice == 14) {
            cout << "Enter the number: ";
            cin >> x;
            result = square_root(x);
            cout << "Result: " << result << endl;
            continue;
        } else if (choice == 15) {
            cout << "Enter the number: ";
            cin >> x;
            result = cube_root(x);
            cout << "Result: " << result << endl;
            continue;
        } else if (choice == 16) {
            cout << "Exiting..." << endl;
            exit = true;
            continue;
        } else {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        if (choice == 1)
            result = add(x, y);
        else if (choice == 2)
            result = subtract(x, y);
        else if (choice == 3)
            result = multiply(x, y);
        else if (choice == 4)
            result = divide(x, y);
        else if (choice == 5)
            result = power(x, y);
        else if (choice == 7)
            result = sine(x);
        else if (choice == 8)
            result = cosine(x);
        else if (choice == 9)
            result = tangent(x);
        else if (choice == 10)
            result = arcsine(x);
        else if (choice == 11)
            result = arccosine(x);
        else if (choice == 12)
            result = arctangent(x);

        cout << "Result: " << result << endl;
    }

    return 0;
}
